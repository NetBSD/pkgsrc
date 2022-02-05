/*
 * Copyright © 2022 Nia Alarie
 *
 * This is a playback-only version of the Sun driver specifically for
 * legacy Firefox (e.g. Arcticfox). Please see the most recent version
 * of the cubeb sources for the record & playback version.
 *
 * This program is made available under an ISC-style license.  See the
 * accompanying file LICENSE for details.
 */
#include <sys/audioio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "cubeb/cubeb.h"
#include "cubeb-internal.h"

#define BYTES_TO_FRAMES(bytes, channels) \
  (bytes / (channels * sizeof(int16_t)))

#define FRAMES_TO_BYTES(frames, channels) \
  (frames * (channels * sizeof(int16_t)))

/* Default to 4 + 1 for the default device. */
#ifndef SUN_DEVICE_COUNT
#define SUN_DEVICE_COUNT (5)
#endif

/* Supported well by most hardware. */
#ifndef SUN_PREFER_RATE
#define SUN_PREFER_RATE (48000)
#endif

/* Standard acceptable minimum. */
#ifndef SUN_LATENCY_MS
#define SUN_LATENCY_MS (40)
#endif

#ifndef SUN_DEFAULT_DEVICE
#define SUN_DEFAULT_DEVICE "/dev/audio"
#endif

#ifndef SUN_POLL_TIMEOUT
#define SUN_POLL_TIMEOUT (1000)
#endif

#ifndef SUN_BUFFER_FRAMES
#define SUN_BUFFER_FRAMES (32)
#endif

/*
 * Supported on NetBSD regardless of hardware.
 */

#ifndef SUN_MAX_CHANNELS
# ifdef __NetBSD__
#  define SUN_MAX_CHANNELS (12)
# else
#  define SUN_MAX_CHANNELS (2)
# endif
#endif

#ifndef SUN_MIN_RATE
#define SUN_MIN_RATE (1000)
#endif

#ifndef SUN_MAX_RATE
#define SUN_MAX_RATE (192000)
#endif

static struct cubeb_ops const sun_ops;

struct cubeb {
  struct cubeb_ops const * ops;
};

struct cubeb_stream {
  struct cubeb * context;
  void * user_ptr;
  pthread_t thread;
  pthread_mutex_t mutex; /* protects running, volume, frames_written */
  int floating;
  int running;
  int play_fd;
  float volume;
  struct audio_info p_info; /* info for the play fd */
  cubeb_data_callback data_cb;
  cubeb_state_callback state_cb;
  int16_t * play_buf;
  float * f_play_buf;
  char output_name[32];
  uint64_t frames_written;
  uint64_t blocks_written;
};

int
sun_init(cubeb ** context, char const * context_name)
{
  cubeb * c;

  (void)context_name;
  if ((c = calloc(1, sizeof(cubeb))) == NULL) {
    return CUBEB_ERROR;
  }
  c->ops = &sun_ops;
  *context = c;
  return CUBEB_OK;
}

static void
sun_destroy(cubeb * context)
{
  free(context);
}

static char const *
sun_get_backend_id(cubeb * context)
{
  return "sun";
}

static int
sun_get_preferred_sample_rate(cubeb * context, uint32_t * rate)
{
  (void)context;

  *rate = SUN_PREFER_RATE;
  return CUBEB_OK;
}

static int
sun_get_max_channel_count(cubeb * context, uint32_t * max_channels)
{
  (void)context;

  *max_channels = SUN_MAX_CHANNELS;
  return CUBEB_OK;
}

static int
sun_get_min_latency(cubeb * context, cubeb_stream_params params,
                    uint32_t * latency_frames)
{
  (void)context;

  *latency_frames = SUN_LATENCY_MS * params.rate / 1000;
  return CUBEB_OK;
}

static int
sun_get_hwinfo(const char * device, struct audio_info * format,
               int * props, struct audio_device * dev)
{
  int fd = -1;

  if ((fd = open(device, O_RDONLY)) == -1) {
    goto error;
  }
#ifdef AUDIO_GETFORMAT
  if (ioctl(fd, AUDIO_GETFORMAT, format) != 0) {
    goto error;
  }
#endif
#ifdef AUDIO_GETPROPS
  if (ioctl(fd, AUDIO_GETPROPS, props) != 0) {
    goto error;
  }
#endif
  if (ioctl(fd, AUDIO_GETDEV, dev) != 0) {
    goto error;
  }
  close(fd);
  return CUBEB_OK;
error:
  if (fd != -1) {
    close(fd);
  }
  return CUBEB_ERROR;
}

/*
 * XXX: PR kern/54264
 */
static int
sun_prinfo_verify_sanity(struct audio_prinfo * prinfo)
{
   return prinfo->precision >= 8 && prinfo->precision <= 32 &&
     prinfo->channels >= 1 && prinfo->channels < SUN_MAX_CHANNELS &&
     prinfo->sample_rate < SUN_MAX_RATE && prinfo->sample_rate > SUN_MIN_RATE;
}

static int
sun_copy_params(int fd, cubeb_stream * stream, cubeb_stream_params * params,
                struct audio_info * info, struct audio_prinfo * prinfo)
{
  prinfo->channels = params->channels;
  prinfo->sample_rate = params->rate;
  prinfo->precision = 16;
#ifdef AUDIO_ENCODING_SLINEAR_LE
  switch (params->format) {
  case CUBEB_SAMPLE_S16LE:
    prinfo->encoding = AUDIO_ENCODING_SLINEAR_LE;
    break;
  case CUBEB_SAMPLE_S16BE:
    prinfo->encoding = AUDIO_ENCODING_SLINEAR_BE;
    break;
  case CUBEB_SAMPLE_FLOAT32NE:
    stream->floating = 1;
    prinfo->encoding = AUDIO_ENCODING_SLINEAR;
    break;
  default:
    return CUBEB_ERROR_INVALID_FORMAT;
  }
#else
  switch (params->format) {
  case CUBEB_SAMPLE_S16NE:
    prinfo->encoding = AUDIO_ENCODING_LINEAR;
    break;
  case CUBEB_SAMPLE_FLOAT32NE:
    stream->floating = 1;
    prinfo->encoding = AUDIO_ENCODING_LINEAR;
    break;
  default:
    return CUBEB_ERROR_INVALID_FORMAT;
  }
#endif
  if (ioctl(fd, AUDIO_SETINFO, info) == -1) {
    return CUBEB_ERROR;
  }
  if (ioctl(fd, AUDIO_GETINFO, info) == -1) {
    return CUBEB_ERROR;
  }
  return CUBEB_OK;
}

static int
sun_stream_stop(cubeb_stream * s)
{
  pthread_mutex_lock(&s->mutex);
  if (s->running) {
    s->running = 0;
    pthread_mutex_unlock(&s->mutex);
    pthread_join(s->thread, NULL);
  } else {
    pthread_mutex_unlock(&s->mutex);
  }
  return CUBEB_OK;
}

static void
sun_stream_destroy(cubeb_stream * s)
{
  pthread_mutex_destroy(&s->mutex);
  sun_stream_stop(s);
  if (s->play_fd != -1) {
    close(s->play_fd);
  }
  free(s->f_play_buf);
  free(s->play_buf);
  free(s);
}

static void
sun_float_to_linear(float * in, int16_t * out,
                    unsigned channels, long frames, float vol)
{
  unsigned i, sample_count = frames * channels;
  float multiplier = vol * 0x8000;

  for (i = 0; i < sample_count; ++i) {
    int32_t sample = lrintf(in[i] * multiplier);
    if (sample < -0x8000) {
      out[i] = -0x8000;
    } else if (sample > 0x7fff) {
      out[i] = 0x7fff;
    } else {
      out[i] = sample;
    }
  }
}

static void
sun_linear_to_float(int16_t * in, float * out,
                    unsigned channels, long frames)
{
  unsigned i, sample_count = frames * channels;

  for (i = 0; i < sample_count; ++i) {
    out[i] = (1.0 / 0x8000) * in[i];
  }
}

static void
sun_linear_set_vol(int16_t * buf, unsigned channels, long frames, float vol)
{
  unsigned i, sample_count = frames * channels;
  int32_t multiplier = vol * 0x8000;

  for (i = 0; i < sample_count; ++i) {
    buf[i] = (buf[i] * multiplier) >> 15;
  }
}

static void *
sun_io_routine(void * arg)
{
  cubeb_stream *s = arg;
  cubeb_state state = CUBEB_STATE_STARTED;
  long to_write = 0;
  size_t write_ofs = 0;
  int drain = 0;

  s->state_cb(s, s->user_ptr, CUBEB_STATE_STARTED);
  while (state != CUBEB_STATE_ERROR) {
    pthread_mutex_lock(&s->mutex);
    if (!s->running) {
      pthread_mutex_unlock(&s->mutex);
      state = CUBEB_STATE_STOPPED;
      break;
    }
    pthread_mutex_unlock(&s->mutex);
    if (s->floating) {
      to_write = s->data_cb(s, s->user_ptr,
                            s->f_play_buf, SUN_BUFFER_FRAMES);
      if (to_write == CUBEB_ERROR) {
        state = CUBEB_STATE_ERROR;
        break;
      }
      if (s->play_fd != -1) {
        pthread_mutex_lock(&s->mutex);
        sun_float_to_linear(s->f_play_buf, s->play_buf,
                            s->p_info.play.channels, to_write, s->volume);
        pthread_mutex_unlock(&s->mutex);
      }
    } else {
      to_write = s->data_cb(s, s->user_ptr,
                            s->play_buf, SUN_BUFFER_FRAMES);
      if (to_write == CUBEB_ERROR) {
        state = CUBEB_STATE_ERROR;
        break;
      }
      if (s->play_fd != -1) {
        pthread_mutex_lock(&s->mutex);
        sun_linear_set_vol(s->play_buf, s->p_info.play.channels, to_write, s->volume);
        pthread_mutex_unlock(&s->mutex);
      }
    }
    if (to_write < SUN_BUFFER_FRAMES) {
      drain = 1;
    }
    to_write = s->play_fd != -1 ? to_write : 0;
    write_ofs = 0;
    while (to_write > 0) {
      size_t bytes;
      ssize_t n, frames;

      if (to_write > 0) {
        bytes = FRAMES_TO_BYTES(to_write, s->p_info.play.channels);
        if ((n = write(s->play_fd, s->play_buf + write_ofs, bytes)) < 0) {
          state = CUBEB_STATE_ERROR;
          break;
        }
        frames = BYTES_TO_FRAMES(n, s->p_info.play.channels);
        pthread_mutex_lock(&s->mutex);
        s->frames_written += frames;
        pthread_mutex_unlock(&s->mutex);
        to_write -= frames;
        write_ofs += frames;
      }
    }
    if (drain && state != CUBEB_STATE_ERROR) {
      state = CUBEB_STATE_DRAINED;
      break;
    }
  }
  s->state_cb(s, s->user_ptr, state);
  return NULL;
}

static int
sun_stream_init(cubeb * context,
                cubeb_stream ** stream,
                char const * stream_name,
                cubeb_stream_params stream_params,
                unsigned latency_frames,
                cubeb_data_callback data_callback,
                cubeb_state_callback state_callback,
                void * user_ptr)
{
  int ret = CUBEB_OK;
  cubeb_stream *s = NULL;

  (void)stream_name;
  (void)latency_frames;
  if ((s = calloc(1, sizeof(cubeb_stream))) == NULL) {
    ret = CUBEB_ERROR;
    goto error;
  }
  snprintf(s->output_name, sizeof(s->output_name), "%s", SUN_DEFAULT_DEVICE);
  if ((s->play_fd = open(s->output_name, O_WRONLY)) == -1) {
    ret = CUBEB_ERROR;
    goto error;
  }
  AUDIO_INITINFO(&s->p_info);
#ifdef AUMODE_PLAY
  s->p_info.mode = AUMODE_PLAY;
#endif
  if ((ret = sun_copy_params(s->play_fd, s, &stream_params,
                             &s->p_info, &s->p_info.play)) != CUBEB_OK) {
    goto error;
  }
  s->context = context;
  s->volume = 1.0;
  s->state_cb = state_callback;
  s->data_cb = data_callback;
  s->user_ptr = user_ptr;
  if (pthread_mutex_init(&s->mutex, NULL) != 0) {
    goto error;
  }
  if (s->play_fd != -1 && (s->play_buf = calloc(SUN_BUFFER_FRAMES,
      s->p_info.play.channels * sizeof(int16_t))) == NULL) {
    ret = CUBEB_ERROR;
    goto error;
  }
  if (s->floating) {
    if (s->play_fd != -1 && (s->f_play_buf = calloc(SUN_BUFFER_FRAMES,
        s->p_info.play.channels * sizeof(float))) == NULL) {
      ret = CUBEB_ERROR;
      goto error;
    }
  }
  *stream = s;
  return CUBEB_OK;
error:
  if (s != NULL) {
    sun_stream_destroy(s);
  }
  return ret;
}

static int
sun_stream_start(cubeb_stream * s)
{
  s->running = 1;
  if (pthread_create(&s->thread, NULL, sun_io_routine, s) != 0) {
    return CUBEB_ERROR;
  }
  return CUBEB_OK;
}

static int
sun_stream_get_position(cubeb_stream * s, uint64_t * position)
{
#ifdef AUDIO_GETOOFFS
  struct audio_offset offset;

  if (ioctl(s->play_fd, AUDIO_GETOOFFS, &offset) == -1) {
    return CUBEB_ERROR;
  }
  s->blocks_written += offset.deltablks;
  *position = BYTES_TO_FRAMES(s->blocks_written * s->p_info.blocksize,
                              s->p_info.play.channels);
  return CUBEB_OK;
#else
  pthread_mutex_lock(&s->mutex);
  *position = s->frames_written;
  pthread_mutex_unlock(&s->mutex);
  return CUBEB_OK;
#endif
}

static int
sun_stream_get_latency(cubeb_stream * stream, uint32_t * latency)
{
#ifdef AUDIO_GETBUFINFO
  struct audio_info info;

  if (ioctl(stream->play_fd, AUDIO_GETBUFINFO, &info) == -1) {
    return CUBEB_ERROR;
  }

  *latency = BYTES_TO_FRAMES(info.play.seek + info.blocksize,
                             info.play.channels);
  return CUBEB_OK;
#else
  cubeb_stream_params params;

  params.rate = stream->p_info.play.sample_rate;

  return sun_get_min_latency(NULL, params, latency);
#endif
}

static int
sun_stream_set_volume(cubeb_stream * stream, float volume)
{
  pthread_mutex_lock(&stream->mutex);
  stream->volume = volume;
  pthread_mutex_unlock(&stream->mutex);
  return CUBEB_OK;
}

static int
sun_get_current_device(cubeb_stream * stream, cubeb_device ** const device)
{
  *device = calloc(1, sizeof(cubeb_device));
  if (*device == NULL) {
    return CUBEB_ERROR;
  }
  (*device)->output_name = stream->play_fd != -1 ?
    strdup(stream->output_name) : NULL;
  return CUBEB_OK;
}

static int
sun_stream_device_destroy(cubeb_stream * stream, cubeb_device * device)
{
  (void)stream;
  free(device->output_name);
  free(device);
  return CUBEB_OK;
}

static struct cubeb_ops const sun_ops = {
  .init = sun_init,
  .get_backend_id = sun_get_backend_id,
  .get_max_channel_count = sun_get_max_channel_count,
  .get_min_latency = sun_get_min_latency,
  .get_preferred_sample_rate = sun_get_preferred_sample_rate,
  .destroy = sun_destroy,
  .stream_init = sun_stream_init,
  .stream_destroy = sun_stream_destroy,
  .stream_start = sun_stream_start,
  .stream_stop = sun_stream_stop,
  .stream_get_position = sun_stream_get_position,
  .stream_get_latency = sun_stream_get_latency,
  .stream_set_volume = sun_stream_set_volume,
  .stream_set_panning = NULL,
  .stream_get_current_device = sun_get_current_device,
  .stream_device_destroy = sun_stream_device_destroy,
  .stream_register_device_changed_callback = NULL
};
