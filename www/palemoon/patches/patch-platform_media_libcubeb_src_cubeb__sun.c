$NetBSD: patch-platform_media_libcubeb_src_cubeb__sun.c,v 1.1 2024/07/26 08:05:23 nia Exp $

Replace with modern version of the driver from current-ish firefox.

Fixes playback artifacts on NetBSD.

--- platform/media/libcubeb/src/cubeb_sun.c.orig	2024-07-25 20:59:35.023700095 +0000
+++ platform/media/libcubeb/src/cubeb_sun.c
@@ -1,81 +1,74 @@
 /*
- * Copyright (c) 2013, 2017 Ginn Chen <ginnchen@gmail.com>
+ * Copyright © 2019-2024 Nia Alarie
  *
  * This program is made available under an ISC-style license.  See the
  * accompanying file LICENSE for details.
  */
-#include <poll.h>
+#include <sys/audioio.h>
+#include <sys/ioctl.h>
+#include <fcntl.h>
+#include <unistd.h>
 #include <pthread.h>
 #include <stdlib.h>
 #include <stdio.h>
-#include <errno.h>
-#include <fcntl.h>
-#include <sys/audio.h>
-#include <sys/stat.h>
-#include <unistd.h>
-#include <sys/stropts.h>
+#include <string.h>
+#include <math.h>
 #include "cubeb/cubeb.h"
 #include "cubeb-internal.h"
 
-/* Macros copied from audio_oss.h */
-/*
- * CDDL HEADER START
- *
- * The contents of this file are subject to the terms of the
- * Common Development and Distribution License (the "License").
- * You may not use this file except in compliance with the License.
- *
- * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
- * or http://www.opensolaris.org/os/licensing.
- * See the License for the specific language governing permissions
- * and limitations under the License.
- *
- * When distributing Covered Code, include this CDDL HEADER in each
- * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
- * If applicable, add the following below this CDDL HEADER, with the
- * fields enclosed by brackets "[]" replaced with your own identifying
- * information: Portions Copyright [yyyy] [name of copyright owner]
- *
- * CDDL HEADER END
- */
+#define CUBEB_OLD_API /* seamonkey and older firefox */
+
+#define BYTES_TO_FRAMES(bytes, channels) \
+  (bytes / (channels * sizeof(int16_t)))
+
+#define FRAMES_TO_BYTES(frames, channels) \
+  (frames * (channels * sizeof(int16_t)))
+
+/* Default to 4 + 1 for the default device. */
+#ifndef SUN_DEVICE_COUNT
+#define SUN_DEVICE_COUNT (5)
+#endif
+
+/* Supported well by most hardware. */
+#ifndef SUN_PREFER_RATE
+#define SUN_PREFER_RATE (48000)
+#endif
+
+/* Standard acceptable minimum. */
+#ifndef SUN_LATENCY_MS
+#define SUN_LATENCY_MS (40)
+#endif
+
+#ifndef SUN_DEFAULT_DEVICE
+#define SUN_DEFAULT_DEVICE "/dev/audio"
+#endif
+
+#ifndef SUN_POLL_TIMEOUT
+#define SUN_POLL_TIMEOUT (1000)
+#endif
+
+#ifndef SUN_BUFFER_FRAMES
+#define SUN_BUFFER_FRAMES (32)
+#endif
+
 /*
- * Copyright (C) 4Front Technologies 1996-2008.
- *
- * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.
- * Use is subject to license terms.
+ * Supported on NetBSD regardless of hardware.
  */
-#define OSSIOCPARM_MASK 0x1fff          /* parameters must be < 8192 bytes */
-#define OSSIOC_VOID     0x00000000      /* no parameters */
-#define OSSIOC_OUT      0x20000000      /* copy out parameters */
-#define OSSIOC_IN       0x40000000      /* copy in parameters */
-#define OSSIOC_INOUT    (OSSIOC_IN|OSSIOC_OUT)
-#define OSSIOC_SZ(t)    ((sizeof (t) & OSSIOCPARM_MASK) << 16)
-#define __OSSIO(x, y)           ((int)(OSSIOC_VOID|(x<<8)|y))
-#define __OSSIOR(x, y, t)       ((int)(OSSIOC_OUT|OSSIOC_SZ(t)|(x<<8)|y))
-#define __OSSIOWR(x, y, t)      ((int)(OSSIOC_INOUT|OSSIOC_SZ(t)|(x<<8)|y))
-#define SNDCTL_DSP_SPEED        __OSSIOWR('P', 2, int)
-#define SNDCTL_DSP_CHANNELS     __OSSIOWR('P', 6, int)
-#define SNDCTL_DSP_SETFMT       __OSSIOWR('P', 5, int)  /* Selects ONE fmt */
-#define SNDCTL_DSP_GETODELAY    __OSSIOR('P', 23, int)
-#define SNDCTL_DSP_HALT_OUTPUT  __OSSIO('P', 34)
-#define AFMT_S16_LE     0x00000010
-#define AFMT_S16_BE     0x00000020
 
-#if defined(WORDS_BIGENDIAN) || defined(__BIG_ENDIAN__)
-#define AFMT_S16_NE    AFMT_S16_BE
-#else
-#define AFMT_S16_NE    AFMT_S16_LE
+#ifndef SUN_MAX_CHANNELS
+# ifdef __NetBSD__
+#  define SUN_MAX_CHANNELS (12)
+# else
+#  define SUN_MAX_CHANNELS (2)
+# endif
 #endif
 
-#define DEFAULT_AUDIO_DEVICE "/dev/audio"
-#define DEFAULT_DSP_DEVICE   "/dev/dsp"
-
-#define BUF_SIZE_MS 10
+#ifndef SUN_MIN_RATE
+#define SUN_MIN_RATE (1000)
+#endif
 
-#if defined(CUBEB_SUNAUDIO_DEBUG)
-#define DPR(...) fprintf(stderr, __VA_ARGS__);
-#else
-#define DPR(...) do {} while(0)
+#ifndef SUN_MAX_RATE
+#define SUN_MAX_RATE (192000)
 #endif
 
 static struct cubeb_ops const sunaudio_ops;
@@ -85,420 +78,680 @@ struct cubeb {
 };
 
 struct cubeb_stream {
-  cubeb * context;
-  pthread_t th;			  /* to run real-time audio i/o */
-  pthread_mutex_t mutex;	  /* protects fd and frm_played */
-  int fd;			  /* link us to sunaudio */
-  int active;			  /* cubec_start() called */
-  int conv;			  /* need float->s16 conversion */
-  int using_oss;
-  unsigned char *buf;		  /* data is prepared here */
-  unsigned int rate;
-  unsigned int n_channles;
-  unsigned int bytes_per_ch;
-  unsigned int n_frm;
-  unsigned int buffer_size;
-  int64_t frm_played;
-  cubeb_data_callback data_cb;    /* cb to preapare data */
-  cubeb_state_callback state_cb;  /* cb to notify about state changes */
-  void *arg;			  /* user arg to {data,state}_cb */
+  struct cubeb * context;
+  void * user_ptr;
+  pthread_t thread;
+  pthread_mutex_t mutex; /* protects running, volume, frames_written */
+  int floating;
+  int running;
+  int play_fd;
+  int record_fd;
+  float volume;
+  struct audio_info p_info; /* info for the play fd */
+  struct audio_info r_info; /* info for the record fd */
+  cubeb_data_callback data_cb;
+  cubeb_state_callback state_cb;
+  int16_t * play_buf;
+  int16_t * record_buf;
+  float * f_play_buf;
+  float * f_record_buf;
+  char input_name[32];
+  char output_name[32];
+  uint64_t frames_written;
+  uint64_t blocks_written;
 };
 
+int
+sunaudio_init(cubeb ** context, char const * context_name)
+{
+  cubeb * c;
+
+  (void)context_name;
+  if ((c = calloc(1, sizeof(cubeb))) == NULL) {
+    return CUBEB_ERROR;
+  }
+  c->ops = &sunaudio_ops;
+  *context = c;
+  return CUBEB_OK;
+}
+
 static void
-float_to_s16(void *ptr, long nsamp)
+sunaudio_destroy(cubeb * context)
 {
-  int16_t *dst = ptr;
-  float *src = ptr;
+  free(context);
+}
 
-  while (nsamp-- > 0)
-    *(dst++) = *(src++) * 32767;
+static char const *
+sunaudio_get_backend_id(cubeb * context)
+{
+  return "sun";
 }
 
-static void *
-sunaudio_mainloop(void *arg)
+static int
+sunaudio_get_preferred_sample_rate(cubeb * context, uint32_t * rate)
 {
-  struct cubeb_stream *s = arg;
-  int state;
+  (void)context;
 
-  DPR("sunaudio_mainloop()\n");
+  *rate = SUN_PREFER_RATE;
+  return CUBEB_OK;
+}
 
-  s->state_cb(s, s->arg, CUBEB_STATE_STARTED);
+static int
+sunaudio_get_max_channel_count(cubeb * context, uint32_t * max_channels)
+{
+  (void)context;
 
-  pthread_mutex_lock(&s->mutex);
-  DPR("sunaudio_mainloop(), started\n");
+  *max_channels = SUN_MAX_CHANNELS;
+  return CUBEB_OK;
+}
 
-  for (;;) {
-    if (!s->active) {
-      DPR("sunaudio_mainloop() stopped\n");
-      state = CUBEB_STATE_STOPPED;
-      break;
-    }
+static int
+sunaudio_get_min_latency(cubeb * context, cubeb_stream_params params,
+                    uint32_t * latency_frames)
+{
+  (void)context;
 
-    if (!s->using_oss) {
-      audio_info_t info;
-      ioctl(s->fd, AUDIO_GETINFO, &info);
-      if (s->frm_played > info.play.samples + 3 * s->n_frm) {
-        pthread_mutex_unlock(&s->mutex);
-        struct timespec ts = {0, 10000}; // 10 ms
-        nanosleep(&ts, NULL);
-        pthread_mutex_lock(&s->mutex);
-        continue;
-      }
-    }
+  *latency_frames = SUN_LATENCY_MS * params.rate / 1000;
+  return CUBEB_OK;
+}
 
-    pthread_mutex_unlock(&s->mutex);
-    unsigned int got = s->data_cb(s, s->arg, NULL, s->buf, s->n_frm);
-    DPR("sunaudio_mainloop() ask %d got %d\n", s->n_frm, got);
-    pthread_mutex_lock(&s->mutex);
+static int
+sunaudio_get_hwinfo(const char * device, struct audio_info * format,
+               int * props, struct audio_device * dev)
+{
+  int fd = -1;
 
-    if (got < 0) {
-      DPR("sunaudio_mainloop() cb err\n");
-      state = CUBEB_STATE_ERROR;
-      break;
-    }
+  if ((fd = open(device, O_RDONLY)) == -1) {
+    goto error;
+  }
+#ifdef AUDIO_GETFORMAT
+  if (ioctl(fd, AUDIO_GETFORMAT, format) != 0) {
+    goto error;
+  }
+#endif
+#ifdef AUDIO_GETPROPS
+  if (ioctl(fd, AUDIO_GETPROPS, props) != 0) {
+    goto error;
+  }
+#endif
+  if (ioctl(fd, AUDIO_GETDEV, dev) != 0) {
+    goto error;
+  }
+  close(fd);
+  return CUBEB_OK;
+error:
+  if (fd != -1) {
+    close(fd);
+  }
+  return CUBEB_ERROR;
+}
 
-    if (s->conv) {
-      float_to_s16(s->buf, got * s->n_channles);
-    }
+/*
+ * XXX: PR kern/54264
+ */
+static int
+sunaudio_prinfo_verify_sanity(struct audio_prinfo * prinfo)
+{
+   return prinfo->precision >= 8 && prinfo->precision <= 32 &&
+     prinfo->channels >= 1 && prinfo->channels < SUN_MAX_CHANNELS &&
+     prinfo->sample_rate < SUN_MAX_RATE && prinfo->sample_rate > SUN_MIN_RATE;
+}
+
+#ifndef CUBEB_OLD_API
+static int
+sunaudio_enumerate_devices(cubeb * context, cubeb_device_type type,
+                      cubeb_device_collection * collection)
+{
+  unsigned i;
+  cubeb_device_info device = {0};
+  char dev[16] = SUN_DEFAULT_DEVICE;
+  char dev_friendly[64];
+  struct audio_info hwfmt;
+  struct audio_device hwname;
+  struct audio_prinfo *prinfo = NULL;
+  int hwprops;
 
-    unsigned int avail = got * 2 * s->n_channles; // coverted to s16
-    unsigned int pos = 0;
+  collection->device = calloc(SUN_DEVICE_COUNT, sizeof(cubeb_device_info));
+  if (collection->device == NULL) {
+    return CUBEB_ERROR;
+  }
+  collection->count = 0;
 
-    while (avail > 0 && s->active) {
-      int written = write(s->fd, s->buf + pos, avail);
-      if (written == -1) {
-        if (errno != EINTR && errno != EWOULDBLOCK) {
-          DPR("sunaudio_mainloop() write err\n");
-          state = CUBEB_STATE_ERROR;
-          break;
-        }
-        pthread_mutex_unlock(&s->mutex);
-        struct timespec ts = {0, 10000}; // 10 ms
-        nanosleep(&ts, NULL);
-        pthread_mutex_lock(&s->mutex);
-      } else {
-        pos += written;
-        DPR("sunaudio_mainloop() write %d pos %d\n", written, pos);
-        s->frm_played += written / 2 / s->n_channles;
-        avail -= written;
+  for (i = 0; i < SUN_DEVICE_COUNT; ++i) {
+    if (i > 0) {
+      (void)snprintf(dev, sizeof(dev), "/dev/audio%u", i - 1);
+    }
+    if (sunaudio_get_hwinfo(dev, &hwfmt, &hwprops, &hwname) != CUBEB_OK) {
+      continue;
+    }
+#ifdef AUDIO_GETPROPS
+    device.type = 0;
+    if ((hwprops & AUDIO_PROP_CAPTURE) != 0 &&
+        sunaudio_prinfo_verify_sanity(&hwfmt.record)) {
+      /* the device supports recording, probably */
+      device.type |= CUBEB_DEVICE_TYPE_INPUT;
+    }
+    if ((hwprops & AUDIO_PROP_PLAYBACK) != 0 &&
+        sunaudio_prinfo_verify_sanity(&hwfmt.play)) {
+      /* the device supports playback, probably */
+      device.type |= CUBEB_DEVICE_TYPE_OUTPUT;
+    }
+    switch (device.type) {
+    case 0:
+      /* device doesn't do input or output, aliens probably involved */
+      continue;
+    case CUBEB_DEVICE_TYPE_INPUT:
+      if ((type & CUBEB_DEVICE_TYPE_INPUT) == 0) {
+        /* this device is input only, not scanning for those, skip it */
+        continue;
       }
-    }
-
-    if ((got  < s->n_frm)) {
-      DPR("sunaudio_mainloop() drained\n");
-      state = CUBEB_STATE_DRAINED;
       break;
+    case CUBEB_DEVICE_TYPE_OUTPUT:
+      if ((type & CUBEB_DEVICE_TYPE_OUTPUT) == 0) {
+        /* this device is output only, not scanning for those, skip it */
+        continue;
+      }
+      break;
+    }
+    if ((type & CUBEB_DEVICE_TYPE_INPUT) != 0) {
+      prinfo = &hwfmt.record;
     }
+    if ((type & CUBEB_DEVICE_TYPE_OUTPUT) != 0) {
+      prinfo = &hwfmt.play;
+    }
+#endif
+    if (i > 0) {
+      (void)snprintf(dev_friendly, sizeof(dev_friendly), "%s %s %s (%d)",
+                     hwname.name, hwname.version, hwname.config, i - 1);
+    } else {
+      (void)snprintf(dev_friendly, sizeof(dev_friendly), "%s %s %s (default)",
+                     hwname.name, hwname.version, hwname.config);
+    }
+    device.devid = (void *)(uintptr_t)i;
+    device.device_id = strdup(dev);
+    device.friendly_name = strdup(dev_friendly);
+    device.group_id = strdup(dev);
+    device.vendor_name = strdup(hwname.name);
+    device.type = type;
+    device.state = CUBEB_DEVICE_STATE_ENABLED;
+    device.preferred = (i == 0) ? CUBEB_DEVICE_PREF_ALL : CUBEB_DEVICE_PREF_NONE;
+#ifdef AUDIO_GETFORMAT
+    device.max_channels = prinfo->channels;
+    device.default_rate = prinfo->sample_rate;
+#else
+    device.max_channels = 2;
+    device.default_rate = SUN_PREFER_RATE;
+#endif
+    device.default_format = CUBEB_DEVICE_FMT_S16NE;
+    device.format = CUBEB_DEVICE_FMT_S16NE;
+    device.min_rate = SUN_MIN_RATE;
+    device.max_rate = SUN_MAX_RATE;
+    device.latency_lo = SUN_LATENCY_MS * SUN_MIN_RATE / 1000;
+    device.latency_hi = SUN_LATENCY_MS * SUN_MAX_RATE / 1000;
+    collection->device[collection->count++] = device;
   }
+  return CUBEB_OK;
+}
+#endif
 
-  pthread_mutex_unlock(&s->mutex);
-  s->state_cb(s, s->arg, state);
+#ifndef CUBEB_OLD_API
+static int
+sunaudio_device_collection_destroy(cubeb * context,
+                              cubeb_device_collection * collection)
+{
+  unsigned i;
 
-  return NULL;
+  for (i = 0; i < collection->count; ++i) {
+    free((char *)collection->device[i].device_id);
+    free((char *)collection->device[i].friendly_name);
+    free((char *)collection->device[i].group_id);
+    free((char *)collection->device[i].vendor_name);
+  }
+  free(collection->device);
+  return CUBEB_OK;
 }
+#endif
 
-/*static*/ int
-sunaudio_init(cubeb **context, char const *context_name)
+static int
+sunaudio_copy_params(int fd, cubeb_stream * stream, cubeb_stream_params * params,
+                struct audio_info * info, struct audio_prinfo * prinfo)
 {
-  DPR("sunaudio_init(%s)\n", context_name);
-  *context = malloc(sizeof(*context));
-  (*context)->ops = &sunaudio_ops;
-  (void)context_name;
+  prinfo->channels = params->channels;
+  prinfo->sample_rate = params->rate;
+  prinfo->precision = 16;
+#ifdef AUDIO_ENCODING_SLINEAR_LE
+  switch (params->format) {
+  case CUBEB_SAMPLE_S16LE:
+    prinfo->encoding = AUDIO_ENCODING_SLINEAR_LE;
+    break;
+  case CUBEB_SAMPLE_S16BE:
+    prinfo->encoding = AUDIO_ENCODING_SLINEAR_BE;
+    break;
+  case CUBEB_SAMPLE_FLOAT32NE:
+    stream->floating = 1;
+    prinfo->encoding = AUDIO_ENCODING_SLINEAR;
+    break;
+  default:
+    return CUBEB_ERROR_INVALID_FORMAT;
+  }
+#else
+  switch (params->format) {
+  case CUBEB_SAMPLE_S16NE:
+    prinfo->encoding = AUDIO_ENCODING_LINEAR;
+    break;
+  case CUBEB_SAMPLE_FLOAT32NE:
+    stream->floating = 1;
+    prinfo->encoding = AUDIO_ENCODING_LINEAR;
+    break;
+  default:
+    return CUBEB_ERROR_INVALID_FORMAT;
+  }
+#endif
+  if (ioctl(fd, AUDIO_SETINFO, info) == -1) {
+    return CUBEB_ERROR;
+  }
+  if (ioctl(fd, AUDIO_GETINFO, info) == -1) {
+    return CUBEB_ERROR;
+  }
   return CUBEB_OK;
 }
 
-static char const *
-sunaudio_get_backend_id(cubeb *context)
+static int
+sunaudio_stream_stop(cubeb_stream * s)
 {
-  return "sunaudio";
+  pthread_mutex_lock(&s->mutex);
+  if (s->running) {
+    s->running = 0;
+    pthread_mutex_unlock(&s->mutex);
+    pthread_join(s->thread, NULL);
+  } else {
+    pthread_mutex_unlock(&s->mutex);
+  }
+  return CUBEB_OK;
 }
 
 static void
-sunaudio_destroy(cubeb *context)
+sunaudio_stream_destroy(cubeb_stream * s)
 {
-  DPR("sunaudio_destroy()\n");
-  free(context);
+  pthread_mutex_destroy(&s->mutex);
+  sunaudio_stream_stop(s);
+  if (s->play_fd != -1) {
+    close(s->play_fd);
+  }
+  if (s->record_fd != -1) {
+    close(s->record_fd);
+  }
+  free(s->f_play_buf);
+  free(s->f_record_buf);
+  free(s->play_buf);
+  free(s->record_buf);
+  free(s);
 }
 
-static int
-sunaudio_stream_init(cubeb *context,
-                  cubeb_stream **stream,
-                  char const *stream_name,
-                  cubeb_devid input_device,
-                  cubeb_stream_params * input_stream_params,
-                  cubeb_devid output_device,
-                  cubeb_stream_params * output_stream_params,
-                  unsigned int latency,
-                  cubeb_data_callback data_callback,
-                  cubeb_state_callback state_callback,
-                  void *user_ptr)
-{
-  struct cubeb_stream *s;
-  DPR("sunaudio_stream_init(%s)\n", stream_name);
-  size_t size;
-
-  s = malloc(sizeof(struct cubeb_stream));
-  if (s == NULL)
-    return CUBEB_ERROR;
-  s->context = context;
+static void
+sunaudio_float_to_linear(float * in, int16_t * out,
+                    unsigned channels, long frames, float vol)
+{
+  unsigned i, sample_count = frames * channels;
+  float multiplier = vol * 0x8000;
 
-  // If UTAUDIODEV is set, use it with Sun Audio interface
-  char * sa_device_name = getenv("UTAUDIODEV");
-  char * dsp_device_name = NULL;
-  if (!sa_device_name) {
-    dsp_device_name = getenv("AUDIODSP");
-    if (!dsp_device_name) {
-      dsp_device_name = DEFAULT_DSP_DEVICE;
-    }
-    sa_device_name = getenv("AUDIODEV");
-    if (!sa_device_name) {
-      sa_device_name = DEFAULT_AUDIO_DEVICE;
+  for (i = 0; i < sample_count; ++i) {
+    int32_t sample = lrintf(in[i] * multiplier);
+    if (sample < -0x8000) {
+      out[i] = -0x8000;
+    } else if (sample > 0x7fff) {
+      out[i] = 0x7fff;
+    } else {
+      out[i] = sample;
     }
   }
+}
 
-  s->using_oss = 0;
-  // Try to use OSS if available
-  if (dsp_device_name) {
-    s->fd = open(dsp_device_name, O_WRONLY | O_NONBLOCK);
-    if (s->fd >= 0) {
-      s->using_oss = 1;
-    }
-  }
+static void
+sunaudio_linear_to_float(int16_t * in, float * out,
+                    unsigned channels, long frames)
+{
+  unsigned i, sample_count = frames * channels;
 
-  // Try Sun Audio
-  if (!s->using_oss) {
-    s->fd = open(sa_device_name, O_WRONLY | O_NONBLOCK);
+  for (i = 0; i < sample_count; ++i) {
+    out[i] = (1.0 / 0x8000) * in[i];
   }
+}
 
-  if (s->fd < 0) {
-    free(s);
-    DPR("sunaudio_stream_init(), open() failed\n");
-    return CUBEB_ERROR;
-  }
+static void
+sunaudio_linear_set_vol(int16_t * buf, unsigned channels, long frames, float vol)
+{
+  unsigned i, sample_count = frames * channels;
+  int32_t multiplier = vol * 0x8000;
 
-  if (s->using_oss) {
-    if (ioctl(s->fd, SNDCTL_DSP_SPEED, &output_stream_params->rate) < 0) {
-      DPR("ioctl SNDCTL_DSP_SPEED failed.\n");
-      close(s->fd);
-      free(s);
-      return CUBEB_ERROR_INVALID_FORMAT;
-    }
-
-    if (ioctl(s->fd, SNDCTL_DSP_CHANNELS, &output_stream_params->channels) < 0) {
-      DPR("ioctl SNDCTL_DSP_CHANNELS failed.\n");
-      close(s->fd);
-      free(s);
-      return CUBEB_ERROR_INVALID_FORMAT;
-    }
-
-    int format = AFMT_S16_NE;
-    if (ioctl(s->fd, SNDCTL_DSP_SETFMT, &format) < 0) {
-      DPR("ioctl SNDCTL_DSP_SETFMT failed.\n");
-      close(s->fd);
-      free(s);
-      return CUBEB_ERROR_INVALID_FORMAT;
-    }
-  } else {
-    audio_info_t audio_info;
-    AUDIO_INITINFO(&audio_info)
-    audio_info.play.sample_rate = output_stream_params->rate;
-    audio_info.play.channels = output_stream_params->channels;
-    audio_info.play.encoding = AUDIO_ENCODING_LINEAR;
-    audio_info.play.precision = 16;
-    if (ioctl(s->fd, AUDIO_SETINFO, &audio_info) == -1) {
-      DPR("ioctl AUDIO_SETINFO failed.\n");
-      close(s->fd);
-      free(s);
-      return CUBEB_ERROR_INVALID_FORMAT;
-    }
+  for (i = 0; i < sample_count; ++i) {
+    buf[i] = (buf[i] * multiplier) >> 15;
   }
+}
 
-  s->conv = 0;
-  switch (output_stream_params->format) {
-    case CUBEB_SAMPLE_S16NE:
-      s->bytes_per_ch = 2;
+static void *
+sunaudio_io_routine(void * arg)
+{
+  cubeb_stream *s = arg;
+  cubeb_state state = CUBEB_STATE_STARTED;
+  size_t to_read = 0;
+  long to_write = 0;
+  size_t write_ofs = 0;
+  size_t read_ofs = 0;
+  int drain = 0;
+
+  s->state_cb(s, s->user_ptr, CUBEB_STATE_STARTED);
+  while (state != CUBEB_STATE_ERROR) {
+    pthread_mutex_lock(&s->mutex);
+    if (!s->running) {
+      pthread_mutex_unlock(&s->mutex);
+      state = CUBEB_STATE_STOPPED;
       break;
-    case CUBEB_SAMPLE_FLOAT32NE:
-      s->bytes_per_ch = 4;
-      s->conv = 1;
+    }
+    pthread_mutex_unlock(&s->mutex);
+    if (s->floating) {
+      if (s->record_fd != -1) {
+        sunaudio_linear_to_float(s->record_buf, s->f_record_buf,
+                            s->r_info.record.channels, SUN_BUFFER_FRAMES);
+      }
+      to_write = s->data_cb(s, s->user_ptr,
+                            s->f_record_buf, s->f_play_buf, SUN_BUFFER_FRAMES);
+      if (to_write == CUBEB_ERROR) {
+        state = CUBEB_STATE_ERROR;
+        break;
+      }
+      if (s->play_fd != -1) {
+        pthread_mutex_lock(&s->mutex);
+        sunaudio_float_to_linear(s->f_play_buf, s->play_buf,
+                            s->p_info.play.channels, to_write, s->volume);
+        pthread_mutex_unlock(&s->mutex);
+      }
+    } else {
+      to_write = s->data_cb(s, s->user_ptr,
+                            s->record_buf, s->play_buf, SUN_BUFFER_FRAMES);
+      if (to_write == CUBEB_ERROR) {
+        state = CUBEB_STATE_ERROR;
+        break;
+      }
+      if (s->play_fd != -1) {
+        pthread_mutex_lock(&s->mutex);
+        sunaudio_linear_set_vol(s->play_buf, s->p_info.play.channels, to_write, s->volume);
+        pthread_mutex_unlock(&s->mutex);
+      }
+    }
+    if (to_write < SUN_BUFFER_FRAMES) {
+      drain = 1;
+    }
+    to_write = s->play_fd != -1 ? to_write : 0;
+    to_read = s->record_fd != -1 ? SUN_BUFFER_FRAMES : 0;
+    write_ofs = 0;
+    read_ofs = 0;
+    while (to_write > 0 || to_read > 0) {
+      size_t bytes;
+      ssize_t n, frames;
+
+      if (to_write > 0) {
+        bytes = FRAMES_TO_BYTES(to_write, s->p_info.play.channels);
+        if ((n = write(s->play_fd, s->play_buf + write_ofs, bytes)) < 0) {
+          state = CUBEB_STATE_ERROR;
+          break;
+        }
+        frames = BYTES_TO_FRAMES(n, s->p_info.play.channels);
+        pthread_mutex_lock(&s->mutex);
+        s->frames_written += frames;
+        pthread_mutex_unlock(&s->mutex);
+        to_write -= frames;
+        write_ofs += frames;
+      }
+      if (to_read > 0) {
+        bytes = FRAMES_TO_BYTES(to_read, s->r_info.record.channels);
+        if ((n = read(s->record_fd, s->record_buf + read_ofs, bytes)) < 0) {
+          state = CUBEB_STATE_ERROR;
+          break;
+        }
+        frames = BYTES_TO_FRAMES(n, s->r_info.record.channels);
+        to_read -= frames;
+        read_ofs += frames;
+      }
+    }
+    if (drain && state != CUBEB_STATE_ERROR) {
+      state = CUBEB_STATE_DRAINED;
       break;
-    default:
-      DPR("sunaudio_stream_init() unsupported format\n");
-      close(s->fd);
-      free(s);
-      return CUBEB_ERROR_INVALID_FORMAT;
+    }
   }
+  s->state_cb(s, s->user_ptr, state);
+  return NULL;
+}
 
-  s->active = 0;
-  s->rate = output_stream_params->rate;
-  s->n_channles = output_stream_params->channels;
-  s->data_cb = data_callback;
+static int
+sunaudio_stream_init(cubeb * context,
+                cubeb_stream ** stream,
+                char const * stream_name,
+                cubeb_devid input_device,
+                cubeb_stream_params * input_stream_params,
+                cubeb_devid output_device,
+                cubeb_stream_params * output_stream_params,
+                unsigned latency_frames,
+                cubeb_data_callback data_callback,
+                cubeb_state_callback state_callback,
+                void * user_ptr)
+{
+  int ret = CUBEB_OK;
+  cubeb_stream *s = NULL;
+
+  (void)stream_name;
+  (void)latency_frames;
+  if ((s = calloc(1, sizeof(cubeb_stream))) == NULL) {
+    ret = CUBEB_ERROR;
+    goto error;
+  }
+  s->record_fd = -1;
+  s->play_fd = -1;
+  if (input_device != 0) {
+    snprintf(s->input_name, sizeof(s->input_name),
+      "/dev/audio%zu", (uintptr_t)input_device - 1);
+  } else {
+    snprintf(s->input_name, sizeof(s->input_name), "%s", SUN_DEFAULT_DEVICE);
+  }
+  if (output_device != 0) {
+    snprintf(s->output_name, sizeof(s->output_name),
+      "/dev/audio%zu", (uintptr_t)output_device - 1);
+  } else {
+    snprintf(s->output_name, sizeof(s->output_name), "%s", SUN_DEFAULT_DEVICE);
+  }
+  if (input_stream_params != NULL) {
+#ifndef CUBEB_OLD_API
+    if (input_stream_params->prefs & CUBEB_STREAM_PREF_LOOPBACK) {
+      ret = CUBEB_ERROR_NOT_SUPPORTED;
+      goto error;
+    }
+#endif
+    if (s->record_fd == -1) {
+      if ((s->record_fd = open(s->input_name, O_RDONLY)) == -1) {
+        ret = CUBEB_ERROR_DEVICE_UNAVAILABLE;
+        goto error;
+      }
+    }
+    AUDIO_INITINFO(&s->r_info);
+#ifdef AUMODE_RECORD
+    s->r_info.mode = AUMODE_RECORD;
+#endif
+    if ((ret = sunaudio_copy_params(s->record_fd, s, input_stream_params,
+                               &s->r_info, &s->r_info.record)) != CUBEB_OK) {
+      goto error;
+    }
+  }
+  if (output_stream_params != NULL) {
+#ifndef CUBEB_OLD_API
+    if (output_stream_params->prefs & CUBEB_STREAM_PREF_LOOPBACK) {
+      ret = CUBEB_ERROR_NOT_SUPPORTED;
+      goto error;
+    }
+#endif
+    if (s->play_fd == -1) {
+      if ((s->play_fd = open(s->output_name, O_WRONLY)) == -1) {
+        ret = CUBEB_ERROR_DEVICE_UNAVAILABLE;
+        goto error;
+      }
+    }
+    AUDIO_INITINFO(&s->p_info);
+#ifdef AUMODE_PLAY
+    s->p_info.mode = AUMODE_PLAY;
+#endif
+    if ((ret = sunaudio_copy_params(s->play_fd, s, output_stream_params,
+                               &s->p_info, &s->p_info.play)) != CUBEB_OK) {
+      goto error;
+    }
+  }
+  s->context = context;
+  s->volume = 1.0;
   s->state_cb = state_callback;
-  s->arg = user_ptr;
+  s->data_cb = data_callback;
+  s->user_ptr = user_ptr;
   if (pthread_mutex_init(&s->mutex, NULL) != 0) {
-    free(s);
-    return CUBEB_ERROR;
+    goto error;
   }
-  s->frm_played = 0;
-  s->n_frm = s->rate * BUF_SIZE_MS / 1000;
-  s->buffer_size = s->bytes_per_ch * s->n_channles * s->n_frm;
-  s->buf = malloc(s->buffer_size);
-  if (s->buf == NULL) {
-    close(s->fd);
-    free(s);
-    return CUBEB_ERROR;
+  if (s->play_fd != -1 && (s->play_buf = calloc(SUN_BUFFER_FRAMES,
+      s->p_info.play.channels * sizeof(int16_t))) == NULL) {
+    ret = CUBEB_ERROR;
+    goto error;
+  }
+  if (s->record_fd != -1 && (s->record_buf = calloc(SUN_BUFFER_FRAMES,
+      s->r_info.record.channels * sizeof(int16_t))) == NULL) {
+    ret = CUBEB_ERROR;
+    goto error;
+  }
+  if (s->floating) {
+    if (s->play_fd != -1 && (s->f_play_buf = calloc(SUN_BUFFER_FRAMES,
+        s->p_info.play.channels * sizeof(float))) == NULL) {
+      ret = CUBEB_ERROR;
+      goto error;
+    }
+    if (s->record_fd != -1 && (s->f_record_buf = calloc(SUN_BUFFER_FRAMES,
+        s->r_info.record.channels * sizeof(float))) == NULL) {
+      ret = CUBEB_ERROR;
+      goto error;
+    }
   }
-
   *stream = s;
-  DPR("sunaudio_stream_init() end, ok\n");
   return CUBEB_OK;
-}
-
-static void
-sunaudio_stream_destroy(cubeb_stream *s)
-{
-  DPR("sunaudio_stream_destroy()\n");
-  if (s->fd > 0) {
-    // Flush buffer
-    if (s->using_oss) {
-      ioctl(s->fd, SNDCTL_DSP_HALT_OUTPUT);
-    } else {
-      ioctl(s->fd, I_FLUSH);
-    }
-    close(s->fd);
+error:
+  if (s != NULL) {
+    sunaudio_stream_destroy(s);
   }
-  free(s->buf);
-  free(s);
+  return ret;
 }
 
 static int
-sunaudio_stream_start(cubeb_stream *s)
+sunaudio_stream_start(cubeb_stream * s)
 {
-  int err;
-
-  DPR("sunaudio_stream_start()\n");
-  s->active = 1;
-  err = pthread_create(&s->th, NULL, sunaudio_mainloop, s);
-  if (err) {
-    s->active = 0;
+  s->running = 1;
+  if (pthread_create(&s->thread, NULL, sunaudio_io_routine, s) != 0) {
     return CUBEB_ERROR;
   }
   return CUBEB_OK;
 }
 
 static int
-sunaudio_stream_stop(cubeb_stream *s)
+sunaudio_stream_get_position(cubeb_stream * s, uint64_t * position)
 {
-  void *dummy;
+#ifdef AUDIO_GETOOFFS
+  struct audio_offset offset;
 
-  DPR("sunaudio_stream_stop()\n");
-  if (s->active) {
-    s->active = 0;
-    pthread_join(s->th, &dummy);
+  if (ioctl(s->play_fd, AUDIO_GETOOFFS, &offset) == -1) {
+    return CUBEB_ERROR;
   }
+  s->blocks_written += offset.deltablks;
+  *position = BYTES_TO_FRAMES(s->blocks_written * s->p_info.blocksize,
+                              s->p_info.play.channels);
   return CUBEB_OK;
-}
-
-static int
-sunaudio_stream_get_position(cubeb_stream *s, uint64_t *p)
-{
-  int rv = CUBEB_OK;
+#else
   pthread_mutex_lock(&s->mutex);
-  if (s->active && s->fd > 0) {
-    if (s->using_oss) {
-      int delay;
-      ioctl(s->fd, SNDCTL_DSP_GETODELAY, &delay);
-      int64_t t = s->frm_played - delay / s->n_channles / 2;
-      if (t < 0) {
-        *p = 0;
-      } else {
-        *p = t;
-      }
-    } else {
-      audio_info_t info;
-      ioctl(s->fd, AUDIO_GETINFO, &info);
-      *p = info.play.samples;
-    }
-    DPR("sunaudio_stream_get_position() %lld\n", *p);
-  } else {
-    rv = CUBEB_ERROR;
-  }
+  *position = s->frames_written;
   pthread_mutex_unlock(&s->mutex);
-  return rv;
+  return CUBEB_OK;
+#endif
 }
 
 static int
-sunaudio_get_max_channel_count(cubeb * ctx, uint32_t * max_channels)
+sunaudio_stream_get_latency(cubeb_stream * stream, uint32_t * latency)
 {
-  if (!ctx || !max_channels)
-    return CUBEB_ERROR;
+#ifdef AUDIO_GETBUFINFO
+  struct audio_info info;
 
-  *max_channels = 2;
+  if (ioctl(stream->play_fd, AUDIO_GETBUFINFO, &info) == -1) {
+    return CUBEB_ERROR;
+  }
 
+  *latency = BYTES_TO_FRAMES(info.play.seek + info.blocksize,
+                             info.play.channels);
   return CUBEB_OK;
+#else
+  cubeb_stream_params params;
+
+  params.rate = stream->p_info.play.sample_rate;
+
+  return sunaudio_get_min_latency(NULL, params, latency);
+#endif
 }
 
 static int
-sunaudio_get_preferred_sample_rate(cubeb * ctx, uint32_t * rate)
+sunaudio_stream_set_volume(cubeb_stream * stream, float volume)
 {
-  if (!ctx || !rate)
-    return CUBEB_ERROR;
-
-  // XXX Not yet implemented.
-  *rate = 44100;
-
+  pthread_mutex_lock(&stream->mutex);
+  stream->volume = volume;
+  pthread_mutex_unlock(&stream->mutex);
   return CUBEB_OK;
 }
 
 static int
-sunaudio_get_min_latency(cubeb * ctx, cubeb_stream_params params, uint32_t * latency_ms)
+sunaudio_get_current_device(cubeb_stream * stream, cubeb_device ** const device)
 {
-  if (!ctx || !latency_ms)
+  *device = calloc(1, sizeof(cubeb_device));
+  if (*device == NULL) {
     return CUBEB_ERROR;
-
-  // XXX Not yet implemented.
-  *latency_ms = 20;
-
+  }
+  (*device)->input_name = stream->record_fd != -1 ?
+    strdup(stream->input_name) : NULL;
+  (*device)->output_name = stream->play_fd != -1 ?
+    strdup(stream->output_name) : NULL;
   return CUBEB_OK;
 }
 
 static int
-sunaudio_stream_get_latency(cubeb_stream * s, uint32_t * latency)
+sunaudio_stream_device_destroy(cubeb_stream * stream, cubeb_device * device)
 {
-  if (!s || !latency)
-    return CUBEB_ERROR;
-
-  int rv = CUBEB_OK;
-  pthread_mutex_lock(&s->mutex);
-  if (s->active && s->fd > 0) {
-    if (s->using_oss) {
-      int delay;
-      ioctl(s->fd, SNDCTL_DSP_GETODELAY, &delay);
-      *latency = delay / s->n_channles / 2 / s->rate;
-    } else {
-      audio_info_t info;
-      ioctl(s->fd, AUDIO_GETINFO, &info);
-      *latency = (s->frm_played - info.play.samples) / s->rate;
-    }
-    DPR("sunaudio_stream_get_position() %lld\n", *p);
-  } else {
-    rv = CUBEB_ERROR;
-  }
-  pthread_mutex_unlock(&s->mutex);
-  return rv;
+  (void)stream;
+  free(device->input_name);
+  free(device->output_name);
+  free(device);
+  return CUBEB_OK;
 }
 
 static struct cubeb_ops const sunaudio_ops = {
   .init = sunaudio_init,
   .get_backend_id = sunaudio_get_backend_id,
-  .destroy = sunaudio_destroy,
+  .get_max_channel_count = sunaudio_get_max_channel_count,
+  .get_min_latency = sunaudio_get_min_latency,
   .get_preferred_sample_rate = sunaudio_get_preferred_sample_rate,
+#ifndef CUBEB_OLD_API
+  .enumerate_devices = sunaudio_enumerate_devices,
+  .device_collection_destroy = sunaudio_device_collection_destroy,
+#endif
+  .destroy = sunaudio_destroy,
   .stream_init = sunaudio_stream_init,
   .stream_destroy = sunaudio_stream_destroy,
   .stream_start = sunaudio_stream_start,
   .stream_stop = sunaudio_stream_stop,
+#ifndef CUBEB_OLD_API
+  .stream_reset_default_device = NULL,
+#endif
   .stream_get_position = sunaudio_stream_get_position,
-  .get_max_channel_count = sunaudio_get_max_channel_count,
-  .get_min_latency = sunaudio_get_min_latency,
-  .stream_get_latency = sunaudio_stream_get_latency
+  .stream_get_latency = sunaudio_stream_get_latency,
+  .stream_set_volume = sunaudio_stream_set_volume,
+  .stream_set_panning = NULL,
+  .stream_get_current_device = sunaudio_get_current_device,
+  .stream_device_destroy = sunaudio_stream_device_destroy,
+  .stream_register_device_changed_callback = NULL,
+  .register_device_collection_changed = NULL
 };
