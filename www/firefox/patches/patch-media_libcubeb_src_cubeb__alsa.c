$NetBSD: patch-media_libcubeb_src_cubeb__alsa.c,v 1.24 2017/09/30 05:34:12 ryoon Exp $

* Support alsa audio under NetBSD
* Avoid https://github.com/kinetiknz/cubeb/issues/226

--- media/libcubeb/src/cubeb_alsa.c.orig	2017-09-14 20:16:05.000000000 +0000
+++ media/libcubeb/src/cubeb_alsa.c
@@ -12,6 +12,7 @@
 #include <sys/time.h>
 #include <assert.h>
 #include <limits.h>
+#include <dlfcn.h>
 #include <poll.h>
 #include <unistd.h>
 #include <alsa/asoundlib.h>
@@ -26,6 +27,52 @@
 
 #define ALSA_PA_PLUGIN "ALSA <-> PulseAudio PCM I/O Plugin"
 
+#ifdef DISABLE_LIBASOUND_DLOPEN
+#define WRAP(x) x
+#else
+#define WRAP(x) cubeb_##x
+#define MAKE_TYPEDEF(x) static typeof(x) * cubeb_##x
+MAKE_TYPEDEF(snd_config);
+MAKE_TYPEDEF(snd_config_add);
+MAKE_TYPEDEF(snd_config_copy);
+MAKE_TYPEDEF(snd_config_delete);
+MAKE_TYPEDEF(snd_config_get_id);
+MAKE_TYPEDEF(snd_config_get_string);
+MAKE_TYPEDEF(snd_config_imake_integer);
+MAKE_TYPEDEF(snd_config_search);
+MAKE_TYPEDEF(snd_config_search_definition);
+MAKE_TYPEDEF(snd_lib_error_set_handler);
+MAKE_TYPEDEF(snd_pcm_avail_update);
+MAKE_TYPEDEF(snd_pcm_close);
+MAKE_TYPEDEF(snd_pcm_delay);
+MAKE_TYPEDEF(snd_pcm_drain);
+MAKE_TYPEDEF(snd_pcm_frames_to_bytes);
+MAKE_TYPEDEF(snd_pcm_get_params);
+/* snd_pcm_hw_params_alloca is actually a macro */
+/* MAKE_TYPEDEF(snd_pcm_hw_params_alloca); */
+MAKE_TYPEDEF(snd_pcm_hw_params_sizeof);
+#define snd_pcm_hw_params_sizeof cubeb_snd_pcm_hw_params_sizeof
+MAKE_TYPEDEF(snd_pcm_hw_params_any);
+MAKE_TYPEDEF(snd_pcm_hw_params_get_channels_max);
+MAKE_TYPEDEF(snd_pcm_hw_params_get_rate);
+MAKE_TYPEDEF(snd_pcm_hw_params_set_rate_near);
+MAKE_TYPEDEF(snd_pcm_nonblock);
+MAKE_TYPEDEF(snd_pcm_open);
+MAKE_TYPEDEF(snd_pcm_open_lconf);
+MAKE_TYPEDEF(snd_pcm_pause);
+MAKE_TYPEDEF(snd_pcm_poll_descriptors);
+MAKE_TYPEDEF(snd_pcm_poll_descriptors_count);
+MAKE_TYPEDEF(snd_pcm_poll_descriptors_revents);
+MAKE_TYPEDEF(snd_pcm_readi);
+MAKE_TYPEDEF(snd_pcm_recover);
+MAKE_TYPEDEF(snd_pcm_set_params);
+MAKE_TYPEDEF(snd_pcm_start);
+MAKE_TYPEDEF(snd_pcm_state);
+MAKE_TYPEDEF(snd_pcm_writei);
+
+#undef MAKE_TYPEDEF
+#endif
+
 /* ALSA is not thread-safe.  snd_pcm_t instances are individually protected
    by the owning cubeb_stream's mutex.  snd_pcm_t creation and destruction
    is not thread-safe until ALSA 1.0.24 (see alsa-lib.git commit 91c9c8f1),
@@ -66,6 +113,8 @@ struct cubeb {
      workaround is not required. */
   snd_config_t * local_config;
   int is_pa;
+
+  void * libasound;
 };
 
 enum stream_state {
@@ -244,8 +293,8 @@ set_timeout(struct timeval * timeout, un
 static void
 stream_buffer_decrement(cubeb_stream * stm, long count)
 {
-  char * bufremains = stm->buffer + snd_pcm_frames_to_bytes(stm->pcm, count);
-  memmove(stm->buffer, bufremains, snd_pcm_frames_to_bytes(stm->pcm, stm->bufframes - count));
+  char * bufremains = stm->buffer + WRAP(snd_pcm_frames_to_bytes)(stm->pcm, count);
+  memmove(stm->buffer, bufremains, WRAP(snd_pcm_frames_to_bytes)(stm->pcm, stm->bufframes - count));
   stm->bufframes -= count;
 }
 
@@ -277,9 +326,9 @@ alsa_process_stream(cubeb_stream * stm)
   /* Call _poll_descriptors_revents() even if we don't use it
      to let underlying plugins clear null events.  Otherwise poll()
      may wake up again and again, producing unnecessary CPU usage. */
-  snd_pcm_poll_descriptors_revents(stm->pcm, stm->fds, stm->nfds, &revents);
+  WRAP(snd_pcm_poll_descriptors_revents)(stm->pcm, stm->fds, stm->nfds, &revents);
 
-  avail = snd_pcm_avail_update(stm->pcm);
+  avail = WRAP(snd_pcm_avail_update)(stm->pcm);
 
   /* Got null event? Bail and wait for another wakeup. */
   if (avail == 0) {
@@ -302,7 +351,7 @@ alsa_process_stream(cubeb_stream * stm)
       // TODO: should it be marked as DRAINING?
     }
 
-    got = snd_pcm_readi(stm->pcm, stm->buffer+stm->bufframes, avail);
+    got = WRAP(snd_pcm_readi)(stm->pcm, stm->buffer+stm->bufframes, avail);
 
     if (got < 0) {
       avail = got; // the error handler below will recover us
@@ -346,7 +395,7 @@ alsa_process_stream(cubeb_stream * stm)
       (!stm->other_stream || stm->other_stream->bufframes > 0)) {
     long got = avail - stm->bufframes;
     void * other_buffer = stm->other_stream ? stm->other_stream->buffer : NULL;
-    char * buftail = stm->buffer + snd_pcm_frames_to_bytes(stm->pcm, stm->bufframes);
+    char * buftail = stm->buffer + WRAP(snd_pcm_frames_to_bytes)(stm->pcm, stm->bufframes);
 
     /* Correct read size to the other stream available frames */
     if (stm->other_stream && got > (snd_pcm_sframes_t) stm->other_stream->bufframes) {
@@ -373,8 +422,8 @@ alsa_process_stream(cubeb_stream * stm)
     long drain_frames = avail - stm->bufframes;
     double drain_time = (double) drain_frames / stm->params.rate;
 
-    char * buftail = stm->buffer + snd_pcm_frames_to_bytes(stm->pcm, stm->bufframes);
-    memset(buftail, 0, snd_pcm_frames_to_bytes(stm->pcm, drain_frames));
+    char * buftail = stm->buffer + WRAP(snd_pcm_frames_to_bytes)(stm->pcm, stm->bufframes);
+    memset(buftail, 0, WRAP(snd_pcm_frames_to_bytes)(stm->pcm, drain_frames));
     stm->bufframes = avail;
 
     /* Mark as draining, unless we're waiting for capture */
@@ -401,7 +450,7 @@ alsa_process_stream(cubeb_stream * stm)
       }
     }
 
-    wrote = snd_pcm_writei(stm->pcm, stm->buffer, avail);
+    wrote = WRAP(snd_pcm_writei)(stm->pcm, stm->buffer, avail);
     if (wrote < 0) {
       avail = wrote; // the error handler below will recover us
     } else {
@@ -414,13 +463,13 @@ alsa_process_stream(cubeb_stream * stm)
 
   /* Got some error? Let's try to recover the stream. */
   if (avail < 0) {
-    avail = snd_pcm_recover(stm->pcm, avail, 0);
+    avail = WRAP(snd_pcm_recover)(stm->pcm, avail, 0);
 
     /* Capture pcm must be started after initial setup/recover */
     if (avail >= 0 &&
         stm->stream_type == SND_PCM_STREAM_CAPTURE &&
-        snd_pcm_state(stm->pcm) == SND_PCM_STATE_PREPARED) {
-      avail = snd_pcm_start(stm->pcm);
+        WRAP(snd_pcm_state)(stm->pcm) == SND_PCM_STATE_PREPARED) {
+      avail = WRAP(snd_pcm_start)(stm->pcm);
     }
   }
 
@@ -536,26 +585,26 @@ get_slave_pcm_node(snd_config_t * lconf,
 
   slave_def = NULL;
 
-  r = snd_config_search(root_pcm, "slave", &slave_pcm);
+  r = WRAP(snd_config_search)(root_pcm, "slave", &slave_pcm);
   if (r < 0) {
     return NULL;
   }
 
-  r = snd_config_get_string(slave_pcm, &string);
+  r = WRAP(snd_config_get_string)(slave_pcm, &string);
   if (r >= 0) {
-    r = snd_config_search_definition(lconf, "pcm_slave", string, &slave_def);
+    r = WRAP(snd_config_search_definition)(lconf, "pcm_slave", string, &slave_def);
     if (r < 0) {
       return NULL;
     }
   }
 
   do {
-    r = snd_config_search(slave_def ? slave_def : slave_pcm, "pcm", &pcm);
+    r = WRAP(snd_config_search)(slave_def ? slave_def : slave_pcm, "pcm", &pcm);
     if (r < 0) {
       break;
     }
 
-    r = snd_config_get_string(slave_def ? slave_def : slave_pcm, &string);
+    r = WRAP(snd_config_get_string)(slave_def ? slave_def : slave_pcm, &string);
     if (r < 0) {
       break;
     }
@@ -564,7 +613,7 @@ get_slave_pcm_node(snd_config_t * lconf,
     if (r < 0 || r > (int) sizeof(node_name)) {
       break;
     }
-    r = snd_config_search(lconf, node_name, &pcm);
+    r = WRAP(snd_config_search)(lconf, node_name, &pcm);
     if (r < 0) {
       break;
     }
@@ -573,7 +622,7 @@ get_slave_pcm_node(snd_config_t * lconf,
   } while (0);
 
   if (slave_def) {
-    snd_config_delete(slave_def);
+    WRAP(snd_config_delete)(slave_def);
   }
 
   return NULL;
@@ -596,22 +645,22 @@ init_local_config_with_workaround(char c
 
   lconf = NULL;
 
-  if (snd_config == NULL) {
+  if (*WRAP(snd_config) == NULL) {
     return NULL;
   }
 
-  r = snd_config_copy(&lconf, snd_config);
+  r = WRAP(snd_config_copy)(&lconf, *WRAP(snd_config));
   if (r < 0) {
     return NULL;
   }
 
   do {
-    r = snd_config_search_definition(lconf, "pcm", pcm_name, &pcm_node);
+    r = WRAP(snd_config_search_definition)(lconf, "pcm", pcm_name, &pcm_node);
     if (r < 0) {
       break;
     }
 
-    r = snd_config_get_id(pcm_node, &string);
+    r = WRAP(snd_config_get_id)(pcm_node, &string);
     if (r < 0) {
       break;
     }
@@ -620,7 +669,7 @@ init_local_config_with_workaround(char c
     if (r < 0 || r > (int) sizeof(node_name)) {
       break;
     }
-    r = snd_config_search(lconf, node_name, &pcm_node);
+    r = WRAP(snd_config_search)(lconf, node_name, &pcm_node);
     if (r < 0) {
       break;
     }
@@ -631,12 +680,12 @@ init_local_config_with_workaround(char c
     }
 
     /* Fetch the PCM node's type, and bail out if it's not the PulseAudio plugin. */
-    r = snd_config_search(pcm_node, "type", &node);
+    r = WRAP(snd_config_search)(pcm_node, "type", &node);
     if (r < 0) {
       break;
     }
 
-    r = snd_config_get_string(node, &string);
+    r = WRAP(snd_config_get_string)(node, &string);
     if (r < 0) {
       break;
     }
@@ -647,18 +696,18 @@ init_local_config_with_workaround(char c
 
     /* Don't clobber an explicit existing handle_underrun value, set it only
        if it doesn't already exist. */
-    r = snd_config_search(pcm_node, "handle_underrun", &node);
+    r = WRAP(snd_config_search)(pcm_node, "handle_underrun", &node);
     if (r != -ENOENT) {
       break;
     }
 
     /* Disable pcm_pulse's asynchronous underrun handling. */
-    r = snd_config_imake_integer(&node, "handle_underrun", 0);
+    r = WRAP(snd_config_imake_integer)(&node, "handle_underrun", 0);
     if (r < 0) {
       break;
     }
 
-    r = snd_config_add(pcm_node, node);
+    r = WRAP(snd_config_add)(pcm_node, node);
     if (r < 0) {
       break;
     }
@@ -666,7 +715,7 @@ init_local_config_with_workaround(char c
     return lconf;
   } while (0);
 
-  snd_config_delete(lconf);
+  WRAP(snd_config_delete)(lconf);
 
   return NULL;
 }
@@ -678,9 +727,9 @@ alsa_locked_pcm_open(snd_pcm_t ** pcm, c
 
   pthread_mutex_lock(&cubeb_alsa_mutex);
   if (local_config) {
-    r = snd_pcm_open_lconf(pcm, pcm_name, stream, SND_PCM_NONBLOCK, local_config);
+    r = WRAP(snd_pcm_open_lconf)(pcm, pcm_name, stream, SND_PCM_NONBLOCK, local_config);
   } else {
-    r = snd_pcm_open(pcm, pcm_name, stream, SND_PCM_NONBLOCK);
+    r = WRAP(snd_pcm_open)(pcm, pcm_name, stream, SND_PCM_NONBLOCK);
   }
   pthread_mutex_unlock(&cubeb_alsa_mutex);
 
@@ -693,7 +742,7 @@ alsa_locked_pcm_close(snd_pcm_t * pcm)
   int r;
 
   pthread_mutex_lock(&cubeb_alsa_mutex);
-  r = snd_pcm_close(pcm);
+  r = WRAP(snd_pcm_close)(pcm);
   pthread_mutex_unlock(&cubeb_alsa_mutex);
 
   return r;
@@ -756,12 +805,65 @@ alsa_init(cubeb ** context, char const *
   pthread_attr_t attr;
   snd_pcm_t * dummy;
 
+  void * libasound = NULL;
+
+#ifndef DISABLE_LIBASOUND_DLOPEN
+  libasound = dlopen("libasound.so", RTLD_LAZY);
+  if (!libasound) {
+    return CUBEB_ERROR;
+  }
+
+#define LOAD(x) do { \
+    cubeb_##x = dlsym(libasound, #x); \
+    if (!cubeb_##x) { \
+      dlclose(libasound); \
+      return CUBEB_ERROR; \
+    } \
+  } while(0)
+
+  LOAD(snd_config);
+  LOAD(snd_config_add);
+  LOAD(snd_config_copy);
+  LOAD(snd_config_delete);
+  LOAD(snd_config_get_id);
+  LOAD(snd_config_get_string);
+  LOAD(snd_config_imake_integer);
+  LOAD(snd_config_search);
+  LOAD(snd_config_search_definition);
+  LOAD(snd_lib_error_set_handler);
+  LOAD(snd_pcm_avail_update);
+  LOAD(snd_pcm_close);
+  LOAD(snd_pcm_delay);
+  LOAD(snd_pcm_drain);
+  LOAD(snd_pcm_frames_to_bytes);
+  LOAD(snd_pcm_get_params);
+  /* snd_pcm_hw_params_alloca is actually a macro */
+  /* LOAD(snd_pcm_hw_params_alloca); */
+  LOAD(snd_pcm_hw_params_sizeof);
+  LOAD(snd_pcm_hw_params_any);
+  LOAD(snd_pcm_hw_params_get_channels_max);
+  LOAD(snd_pcm_hw_params_get_rate);
+  LOAD(snd_pcm_hw_params_set_rate_near);
+  LOAD(snd_pcm_nonblock);
+  LOAD(snd_pcm_open);
+  LOAD(snd_pcm_open_lconf);
+  LOAD(snd_pcm_pause);
+  LOAD(snd_pcm_poll_descriptors);
+  LOAD(snd_pcm_poll_descriptors_count);
+  LOAD(snd_pcm_poll_descriptors_revents);
+  LOAD(snd_pcm_recover);
+  LOAD(snd_pcm_set_params);
+  LOAD(snd_pcm_state);
+  LOAD(snd_pcm_writei);
+
+#undef LOAD
+#endif
   assert(context);
   *context = NULL;
 
   pthread_mutex_lock(&cubeb_alsa_mutex);
   if (!cubeb_alsa_error_handler_set) {
-    snd_lib_error_set_handler(silent_error_handler);
+    WRAP(snd_lib_error_set_handler)(silent_error_handler);
     cubeb_alsa_error_handler_set = 1;
   }
   pthread_mutex_unlock(&cubeb_alsa_mutex);
@@ -769,6 +871,8 @@ alsa_init(cubeb ** context, char const *
   ctx = calloc(1, sizeof(*ctx));
   assert(ctx);
 
+  ctx->libasound = libasound;
+
   ctx->ops = &alsa_ops;
 
   r = pthread_mutex_init(&ctx->mutex, NULL);
@@ -818,7 +922,7 @@ alsa_init(cubeb ** context, char const *
        config fails with EINVAL, the PA PCM is too old for this workaround. */
     if (r == -EINVAL) {
       pthread_mutex_lock(&cubeb_alsa_mutex);
-      snd_config_delete(ctx->local_config);
+      WRAP(snd_config_delete)(ctx->local_config);
       pthread_mutex_unlock(&cubeb_alsa_mutex);
       ctx->local_config = NULL;
     } else if (r >= 0) {
@@ -858,9 +962,13 @@ alsa_destroy(cubeb * ctx)
   pthread_mutex_destroy(&ctx->mutex);
   free(ctx->fds);
 
+  if (ctx->libasound) {
+    dlclose(ctx->libasound);
+  }
+
   if (ctx->local_config) {
     pthread_mutex_lock(&cubeb_alsa_mutex);
-    snd_config_delete(ctx->local_config);
+    WRAP(snd_config_delete)(ctx->local_config);
     pthread_mutex_unlock(&cubeb_alsa_mutex);
   }
 
@@ -943,7 +1051,7 @@ alsa_stream_init_single(cubeb * ctx, cub
     return CUBEB_ERROR;
   }
 
-  r = snd_pcm_nonblock(stm->pcm, 1);
+  r = WRAP(snd_pcm_nonblock)(stm->pcm, 1);
   assert(r == 0);
 
   latency_us = latency_frames * 1e6 / stm->params.rate;
@@ -956,7 +1064,7 @@ alsa_stream_init_single(cubeb * ctx, cub
     latency_us = latency_us < min_latency ? min_latency: latency_us;
   }
 
-  r = snd_pcm_set_params(stm->pcm, format, SND_PCM_ACCESS_RW_INTERLEAVED,
+  r = WRAP(snd_pcm_set_params)(stm->pcm, format, SND_PCM_ACCESS_RW_INTERLEAVED,
                          stm->params.channels, stm->params.rate, 1,
                          latency_us);
   if (r < 0) {
@@ -964,20 +1072,20 @@ alsa_stream_init_single(cubeb * ctx, cub
     return CUBEB_ERROR_INVALID_FORMAT;
   }
 
-  r = snd_pcm_get_params(stm->pcm, &stm->buffer_size, &period_size);
+  r = WRAP(snd_pcm_get_params)(stm->pcm, &stm->buffer_size, &period_size);
   assert(r == 0);
 
   /* Double internal buffer size to have enough space when waiting for the other side of duplex connection */
   stm->buffer_size *= 2;
-  stm->buffer = calloc(1, snd_pcm_frames_to_bytes(stm->pcm, stm->buffer_size));
+  stm->buffer = calloc(1, WRAP(snd_pcm_frames_to_bytes)(stm->pcm, stm->buffer_size));
   assert(stm->buffer);
 
-  stm->nfds = snd_pcm_poll_descriptors_count(stm->pcm);
+  stm->nfds = WRAP(snd_pcm_poll_descriptors_count)(stm->pcm);
   assert(stm->nfds > 0);
 
   stm->saved_fds = calloc(stm->nfds, sizeof(struct pollfd));
   assert(stm->saved_fds);
-  r = snd_pcm_poll_descriptors(stm->pcm, stm->saved_fds, stm->nfds);
+  r = WRAP(snd_pcm_poll_descriptors)(stm->pcm, stm->saved_fds, stm->nfds);
   assert((nfds_t) r == stm->nfds);
 
   if (alsa_register_stream(ctx, stm) != 0) {
@@ -1049,7 +1157,7 @@ alsa_stream_destroy(cubeb_stream * stm)
   pthread_mutex_lock(&stm->mutex);
   if (stm->pcm) {
     if (stm->state == DRAINING) {
-      snd_pcm_drain(stm->pcm);
+      WRAP(snd_pcm_drain)(stm->pcm);
     }
     alsa_locked_pcm_close(stm->pcm);
     stm->pcm = NULL;
@@ -1095,12 +1203,12 @@ alsa_get_max_channel_count(cubeb * ctx, 
 
   assert(stm);
 
-  r = snd_pcm_hw_params_any(stm->pcm, hw_params);
+  r = WRAP(snd_pcm_hw_params_any)(stm->pcm, hw_params);
   if (r < 0) {
     return CUBEB_ERROR;
   }
 
-  r = snd_pcm_hw_params_get_channels_max(hw_params, max_channels);
+  r = WRAP(snd_pcm_hw_params_get_channels_max)(hw_params, max_channels);
   if (r < 0) {
     return CUBEB_ERROR;
   }
@@ -1121,34 +1229,34 @@ alsa_get_preferred_sample_rate(cubeb * c
 
   /* get a pcm, disabling resampling, so we get a rate the
    * hardware/dmix/pulse/etc. supports. */
-  r = snd_pcm_open(&pcm, CUBEB_ALSA_PCM_NAME, SND_PCM_STREAM_PLAYBACK, SND_PCM_NO_AUTO_RESAMPLE);
+  r = WRAP(snd_pcm_open)(&pcm, CUBEB_ALSA_PCM_NAME, SND_PCM_STREAM_PLAYBACK, SND_PCM_NO_AUTO_RESAMPLE);
   if (r < 0) {
     return CUBEB_ERROR;
   }
 
-  r = snd_pcm_hw_params_any(pcm, hw_params);
+  r = WRAP(snd_pcm_hw_params_any)(pcm, hw_params);
   if (r < 0) {
-    snd_pcm_close(pcm);
+    WRAP(snd_pcm_close)(pcm);
     return CUBEB_ERROR;
   }
 
-  r = snd_pcm_hw_params_get_rate(hw_params, rate, &dir);
+  r = WRAP(snd_pcm_hw_params_get_rate)(hw_params, rate, &dir);
   if (r >= 0) {
     /* There is a default rate: use it. */
-    snd_pcm_close(pcm);
+    WRAP(snd_pcm_close)(pcm);
     return CUBEB_OK;
   }
 
   /* Use a common rate, alsa may adjust it based on hw/etc. capabilities. */
   *rate = 44100;
 
-  r = snd_pcm_hw_params_set_rate_near(pcm, hw_params, rate, NULL);
+  r = WRAP(snd_pcm_hw_params_set_rate_near)(pcm, hw_params, rate, NULL);
   if (r < 0) {
-    snd_pcm_close(pcm);
+    WRAP(snd_pcm_close)(pcm);
     return CUBEB_ERROR;
   }
 
-  snd_pcm_close(pcm);
+  WRAP(snd_pcm_close)(pcm);
 
   return CUBEB_OK;
 }
@@ -1181,10 +1289,10 @@ alsa_stream_start(cubeb_stream * stm)
   pthread_mutex_lock(&stm->mutex);
   /* Capture pcm must be started after initial setup/recover */
   if (stm->stream_type == SND_PCM_STREAM_CAPTURE &&
-      snd_pcm_state(stm->pcm) == SND_PCM_STATE_PREPARED) {
-    snd_pcm_start(stm->pcm);
+      WRAP(snd_pcm_state)(stm->pcm) == SND_PCM_STATE_PREPARED) {
+    WRAP(snd_pcm_start)(stm->pcm);
   }
-  snd_pcm_pause(stm->pcm, 0);
+  WRAP(snd_pcm_pause)(stm->pcm, 0);
   gettimeofday(&stm->last_activity, NULL);
   pthread_mutex_unlock(&stm->mutex);
 
@@ -1224,7 +1332,7 @@ alsa_stream_stop(cubeb_stream * stm)
   pthread_mutex_unlock(&ctx->mutex);
 
   pthread_mutex_lock(&stm->mutex);
-  snd_pcm_pause(stm->pcm, 1);
+  WRAP(snd_pcm_pause)(stm->pcm, 1);
   pthread_mutex_unlock(&stm->mutex);
 
   return CUBEB_OK;
@@ -1240,8 +1348,8 @@ alsa_stream_get_position(cubeb_stream * 
   pthread_mutex_lock(&stm->mutex);
 
   delay = -1;
-  if (snd_pcm_state(stm->pcm) != SND_PCM_STATE_RUNNING ||
-      snd_pcm_delay(stm->pcm, &delay) != 0) {
+  if (WRAP(snd_pcm_state)(stm->pcm) != SND_PCM_STATE_RUNNING ||
+      WRAP(snd_pcm_delay)(stm->pcm, &delay) != 0) {
     *position = stm->last_position;
     pthread_mutex_unlock(&stm->mutex);
     return CUBEB_OK;
@@ -1266,7 +1374,7 @@ alsa_stream_get_latency(cubeb_stream * s
   snd_pcm_sframes_t delay;
   /* This function returns the delay in frames until a frame written using
      snd_pcm_writei is sent to the DAC. The DAC delay should be < 1ms anyways. */
-  if (snd_pcm_delay(stm->pcm, &delay)) {
+  if (WRAP(snd_pcm_delay)(stm->pcm, &delay)) {
     return CUBEB_ERROR;
   }
 
