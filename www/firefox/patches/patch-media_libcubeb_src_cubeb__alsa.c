$NetBSD: patch-media_libcubeb_src_cubeb__alsa.c,v 1.6 2015/02/16 16:13:50 bad Exp $

--- media/libcubeb/src/cubeb_alsa.c.orig	2015-01-23 05:59:59.000000000 +0000
+++ media/libcubeb/src/cubeb_alsa.c	2015-02-16 12:55:41.000000000 +0000
@@ -6,12 +6,17 @@
  */
 #undef NDEBUG
 #define _BSD_SOURCE
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE
+#endif
 #define _XOPEN_SOURCE 500
 #include <pthread.h>
 #include <sys/time.h>
 #include <assert.h>
 #include <limits.h>
+#include <dlfcn.h>
 #include <poll.h>
+#include <stdio.h>
 #include <unistd.h>
 #include <alsa/asoundlib.h>
 #include "cubeb/cubeb.h"
@@ -24,6 +29,50 @@
 
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
+MAKE_TYPEDEF(snd_pcm_recover);
+MAKE_TYPEDEF(snd_pcm_set_params);
+MAKE_TYPEDEF(snd_pcm_state);
+MAKE_TYPEDEF(snd_pcm_writei);
+
+#undef MAKE_TYPEDEF
+#endif
+
 /* ALSA is not thread-safe.  snd_pcm_t instances are individually protected
    by the owning cubeb_stream's mutex.  snd_pcm_t creation and destruction
    is not thread-safe until ALSA 1.0.24 (see alsa-lib.git commit 91c9c8f1),
@@ -64,6 +113,8 @@
      workaround is not required. */
   snd_config_t * local_config;
   int is_pa;
+
+  void * libasound;
 };
 
 enum stream_state {
@@ -262,7 +313,7 @@
 
   pthread_mutex_lock(&stm->mutex);
 
-  r = snd_pcm_poll_descriptors_revents(stm->pcm, stm->fds, stm->nfds, &revents);
+  r = WRAP(snd_pcm_poll_descriptors_revents)(stm->pcm, stm->fds, stm->nfds, &revents);
   if (r < 0 || revents != POLLOUT) {
     /* This should be a stream error; it makes no sense for poll(2) to wake
        for this stream and then have the stream report that it's not ready.
@@ -271,10 +322,10 @@
     return RUNNING;
   }
 
-  avail = snd_pcm_avail_update(stm->pcm);
+  avail = WRAP(snd_pcm_avail_update)(stm->pcm);
   if (avail == -EPIPE) {
-    snd_pcm_recover(stm->pcm, avail, 1);
-    avail = snd_pcm_avail_update(stm->pcm);
+    WRAP(snd_pcm_recover)(stm->pcm, avail, 1);
+    avail = WRAP(snd_pcm_avail_update)(stm->pcm);
   }
 
   /* Failed to recover from an xrun, this stream must be broken. */
@@ -293,8 +344,8 @@
      available to write.  If avail is still zero here, the stream must be in
      a funky state, so recover and try again. */
   if (avail == 0) {
-    snd_pcm_recover(stm->pcm, -EPIPE, 1);
-    avail = snd_pcm_avail_update(stm->pcm);
+    WRAP(snd_pcm_recover)(stm->pcm, -EPIPE, 1);
+    avail = WRAP(snd_pcm_avail_update)(stm->pcm);
     if (avail <= 0) {
       pthread_mutex_unlock(&stm->mutex);
       stm->state_callback(stm, stm->user_ptr, CUBEB_STATE_ERROR);
@@ -302,7 +353,7 @@
     }
   }
 
-  p = calloc(1, snd_pcm_frames_to_bytes(stm->pcm, avail));
+  p = calloc(1, WRAP(snd_pcm_frames_to_bytes)(stm->pcm, avail));
   assert(p);
 
   pthread_mutex_unlock(&stm->mutex);
@@ -327,10 +378,10 @@
         b[i] *= stm->volume;
       }
     }
-    wrote = snd_pcm_writei(stm->pcm, p, got);
+    wrote = WRAP(snd_pcm_writei)(stm->pcm, p, got);
     if (wrote == -EPIPE) {
-      snd_pcm_recover(stm->pcm, wrote, 1);
-      wrote = snd_pcm_writei(stm->pcm, p, got);
+      WRAP(snd_pcm_recover)(stm->pcm, wrote, 1);
+      wrote = WRAP(snd_pcm_writei)(stm->pcm, p, got);
     }
     assert(wrote >= 0 && wrote == got);
     stm->write_position += wrote;
@@ -342,7 +393,7 @@
 
     /* Fill the remaining buffer with silence to guarantee one full period
        has been written. */
-    snd_pcm_writei(stm->pcm, (char *) p + got, avail - got);
+    WRAP(snd_pcm_writei)(stm->pcm, (char *) p + got, avail - got);
 
     set_timeout(&stm->drain_timeout, buffer_time * 1000);
 
@@ -453,26 +504,26 @@
 
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
@@ -481,7 +532,7 @@
     if (r < 0 || r > (int) sizeof(node_name)) {
       break;
     }
-    r = snd_config_search(lconf, node_name, &pcm);
+    r = WRAP(snd_config_search)(lconf, node_name, &pcm);
     if (r < 0) {
       break;
     }
@@ -490,7 +541,7 @@
   } while (0);
 
   if (slave_def) {
-    snd_config_delete(slave_def);
+    WRAP(snd_config_delete)(slave_def);
   }
 
   return NULL;
@@ -513,22 +564,22 @@
 
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
@@ -537,7 +588,7 @@
     if (r < 0 || r > (int) sizeof(node_name)) {
       break;
     }
-    r = snd_config_search(lconf, node_name, &pcm_node);
+    r = WRAP(snd_config_search)(lconf, node_name, &pcm_node);
     if (r < 0) {
       break;
     }
@@ -548,12 +599,12 @@
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
@@ -564,18 +615,18 @@
 
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
@@ -583,7 +634,7 @@
     return lconf;
   } while (0);
 
-  snd_config_delete(lconf);
+  WRAP(snd_config_delete)(lconf);
 
   return NULL;
 }
@@ -595,9 +646,9 @@
 
   pthread_mutex_lock(&cubeb_alsa_mutex);
   if (local_config) {
-    r = snd_pcm_open_lconf(pcm, CUBEB_ALSA_PCM_NAME, stream, SND_PCM_NONBLOCK, local_config);
+    r = WRAP(snd_pcm_open_lconf)(pcm, CUBEB_ALSA_PCM_NAME, stream, SND_PCM_NONBLOCK, local_config);
   } else {
-    r = snd_pcm_open(pcm, CUBEB_ALSA_PCM_NAME, stream, SND_PCM_NONBLOCK);
+    r = WRAP(snd_pcm_open)(pcm, CUBEB_ALSA_PCM_NAME, stream, SND_PCM_NONBLOCK);
   }
   pthread_mutex_unlock(&cubeb_alsa_mutex);
 
@@ -610,7 +661,7 @@
   int r;
 
   pthread_mutex_lock(&cubeb_alsa_mutex);
-  r = snd_pcm_close(pcm);
+  r = WRAP(snd_pcm_close)(pcm);
   pthread_mutex_unlock(&cubeb_alsa_mutex);
 
   return r;
@@ -667,12 +718,65 @@
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
@@ -680,6 +784,8 @@
   ctx = calloc(1, sizeof(*ctx));
   assert(ctx);
 
+  ctx->libasound = libasound;
+
   ctx->ops = &alsa_ops;
 
   r = pthread_mutex_init(&ctx->mutex, NULL);
@@ -729,7 +835,7 @@
        config fails with EINVAL, the PA PCM is too old for this workaround. */
     if (r == -EINVAL) {
       pthread_mutex_lock(&cubeb_alsa_mutex);
-      snd_config_delete(ctx->local_config);
+      WRAP(snd_config_delete)(ctx->local_config);
       pthread_mutex_unlock(&cubeb_alsa_mutex);
       ctx->local_config = NULL;
     } else if (r >= 0) {
@@ -768,9 +874,13 @@
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
 
@@ -838,7 +948,7 @@
     return CUBEB_ERROR;
   }
 
-  r = snd_pcm_nonblock(stm->pcm, 1);
+  r = WRAP(snd_pcm_nonblock)(stm->pcm, 1);
   assert(r == 0);
 
   /* Ugly hack: the PA ALSA plugin allows buffer configurations that can't
@@ -848,23 +958,23 @@
     latency = latency < 500 ? 500 : latency;
   }
 
-  r = snd_pcm_set_params(stm->pcm, format, SND_PCM_ACCESS_RW_INTERLEAVED,
-                         stm->params.channels, stm->params.rate, 1,
-                         latency * 1000);
+  r = WRAP(snd_pcm_set_params)(stm->pcm, format, SND_PCM_ACCESS_RW_INTERLEAVED,
+                               stm->params.channels, stm->params.rate, 1,
+                               latency * 1000);
   if (r < 0) {
     alsa_stream_destroy(stm);
     return CUBEB_ERROR_INVALID_FORMAT;
   }
 
-  r = snd_pcm_get_params(stm->pcm, &stm->buffer_size, &stm->period_size);
+  r = WRAP(snd_pcm_get_params)(stm->pcm, &stm->buffer_size, &stm->period_size);
   assert(r == 0);
 
-  stm->nfds = snd_pcm_poll_descriptors_count(stm->pcm);
+  stm->nfds = WRAP(snd_pcm_poll_descriptors_count)(stm->pcm);
   assert(stm->nfds > 0);
 
   stm->saved_fds = calloc(stm->nfds, sizeof(struct pollfd));
   assert(stm->saved_fds);
-  r = snd_pcm_poll_descriptors(stm->pcm, stm->saved_fds, stm->nfds);
+  r = WRAP(snd_pcm_poll_descriptors)(stm->pcm, stm->saved_fds, stm->nfds);
   assert((nfds_t) r == stm->nfds);
 
   r = pthread_cond_init(&stm->cond, NULL);
@@ -895,7 +1005,7 @@
   pthread_mutex_lock(&stm->mutex);
   if (stm->pcm) {
     if (stm->state == DRAINING) {
-      snd_pcm_drain(stm->pcm);
+      WRAP(snd_pcm_drain)(stm->pcm);
     }
     alsa_locked_pcm_close(stm->pcm);
     stm->pcm = NULL;
@@ -905,7 +1015,9 @@
   pthread_mutex_destroy(&stm->mutex);
 
   r = pthread_cond_destroy(&stm->cond);
-  assert(r == 0);
+  if (r != 0) {	/* XXX stopgap until someone figures out the real reason */
+    perror("alsa_stream_destroy: pthread_cond_destroy failed");
+  }
 
   alsa_unregister_stream(stm);
 
@@ -937,12 +1049,12 @@
     return CUBEB_ERROR;
   }
 
-  rv = snd_pcm_hw_params_any(stm->pcm, hw_params);
+  rv = WRAP(snd_pcm_hw_params_any)(stm->pcm, hw_params);
   if (rv < 0) {
     return CUBEB_ERROR;
   }
 
-  rv = snd_pcm_hw_params_get_channels_max(hw_params, max_channels);
+  rv = WRAP(snd_pcm_hw_params_get_channels_max)(hw_params, max_channels);
   if (rv < 0) {
     return CUBEB_ERROR;
   }
@@ -962,34 +1074,34 @@
 
   /* get a pcm, disabling resampling, so we get a rate the
    * hardware/dmix/pulse/etc. supports. */
-  rv = snd_pcm_open(&pcm, "", SND_PCM_STREAM_PLAYBACK | SND_PCM_NO_AUTO_RESAMPLE, 0);
+  rv = WRAP(snd_pcm_open)(&pcm, "", SND_PCM_STREAM_PLAYBACK | SND_PCM_NO_AUTO_RESAMPLE, 0);
   if (rv < 0) {
     return CUBEB_ERROR;
   }
 
-  rv = snd_pcm_hw_params_any(pcm, hw_params);
+  rv = WRAP(snd_pcm_hw_params_any)(pcm, hw_params);
   if (rv < 0) {
-    snd_pcm_close(pcm);
+    WRAP(snd_pcm_close)(pcm);
     return CUBEB_ERROR;
   }
 
-  rv = snd_pcm_hw_params_get_rate(hw_params, rate, &dir);
+  rv = WRAP(snd_pcm_hw_params_get_rate)(hw_params, rate, &dir);
   if (rv >= 0) {
     /* There is a default rate: use it. */
-    snd_pcm_close(pcm);
+    WRAP(snd_pcm_close)(pcm);
     return CUBEB_OK;
   }
 
   /* Use a common rate, alsa may adjust it based on hw/etc. capabilities. */
   *rate = 44100;
 
-  rv = snd_pcm_hw_params_set_rate_near(pcm, hw_params, rate, NULL);
+  rv = WRAP(snd_pcm_hw_params_set_rate_near)(pcm, hw_params, rate, NULL);
   if (rv < 0) {
-    snd_pcm_close(pcm);
+    WRAP(snd_pcm_close)(pcm);
     return CUBEB_ERROR;
   }
 
-  snd_pcm_close(pcm);
+  WRAP(snd_pcm_close)(pcm);
 
   return CUBEB_OK;
 }
@@ -1013,7 +1125,7 @@
   ctx = stm->context;
 
   pthread_mutex_lock(&stm->mutex);
-  snd_pcm_pause(stm->pcm, 0);
+  WRAP(snd_pcm_pause)(stm->pcm, 0);
   gettimeofday(&stm->last_activity, NULL);
   pthread_mutex_unlock(&stm->mutex);
 
@@ -1047,7 +1159,7 @@
   pthread_mutex_unlock(&ctx->mutex);
 
   pthread_mutex_lock(&stm->mutex);
-  snd_pcm_pause(stm->pcm, 1);
+  WRAP(snd_pcm_pause)(stm->pcm, 1);
   pthread_mutex_unlock(&stm->mutex);
 
   return CUBEB_OK;
@@ -1063,8 +1175,8 @@
   pthread_mutex_lock(&stm->mutex);
 
   delay = -1;
-  if (snd_pcm_state(stm->pcm) != SND_PCM_STATE_RUNNING ||
-      snd_pcm_delay(stm->pcm, &delay) != 0) {
+  if (WRAP(snd_pcm_state)(stm->pcm) != SND_PCM_STATE_RUNNING ||
+      WRAP(snd_pcm_delay)(stm->pcm, &delay) != 0) {
     *position = stm->last_position;
     pthread_mutex_unlock(&stm->mutex);
     return CUBEB_OK;
@@ -1089,7 +1201,7 @@
   snd_pcm_sframes_t delay;
   /* This function returns the delay in frames until a frame written using
      snd_pcm_writei is sent to the DAC. The DAC delay should be < 1ms anyways. */
-  if (snd_pcm_delay(stm->pcm, &delay)) {
+  if (WRAP(snd_pcm_delay)(stm->pcm, &delay)) {
     return CUBEB_ERROR;
   }
 
