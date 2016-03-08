$NetBSD: patch-media_libcubeb_src_cubeb__alsa.c,v 1.13 2016/03/08 21:32:52 ryoon Exp $

--- media/libcubeb/src/cubeb_alsa.c.orig	2016-02-25 23:01:58.000000000 +0000
+++ media/libcubeb/src/cubeb_alsa.c
@@ -7,12 +7,18 @@
 #undef NDEBUG
 #define _DEFAULT_SOURCE
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
+#include <stdlib.h>
+#include <stdio.h>
 #include <unistd.h>
 #include <alsa/asoundlib.h>
 #include "cubeb/cubeb.h"
@@ -25,6 +31,51 @@
 
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
+MAKE_TYPEDEF(snd_pcm_forward);
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
@@ -65,6 +116,8 @@ struct cubeb {
      workaround is not required. */
   snd_config_t * local_config;
   int is_pa;
+
+  void * libasound;
 };
 
 enum stream_state {
@@ -258,32 +311,35 @@ alsa_refill_stream(cubeb_stream * stm)
   long got;
   void * p;
   int draining;
+  unsigned pipefailures, againfailures;
 
   draining = 0;
 
   pthread_mutex_lock(&stm->mutex);
 
-  r = snd_pcm_poll_descriptors_revents(stm->pcm, stm->fds, stm->nfds, &revents);
-  if (r < 0 || revents != POLLOUT) {
-    /* This should be a stream error; it makes no sense for poll(2) to wake
-       for this stream and then have the stream report that it's not ready.
-       Unfortunately, this does happen, so just bail out and try again. */
-    pthread_mutex_unlock(&stm->mutex);
-    return RUNNING;
-  }
-
-  avail = snd_pcm_avail_update(stm->pcm);
-  if (avail == -EPIPE) {
-    snd_pcm_recover(stm->pcm, avail, 1);
-    avail = snd_pcm_avail_update(stm->pcm);
-  }
+  for (pipefailures = 0;;) {
+    r = WRAP(snd_pcm_poll_descriptors_revents)(stm->pcm, stm->fds, stm->nfds, &revents);
+    if (r < 0 || revents != POLLOUT ||
+      (avail = WRAP(snd_pcm_avail_update)(stm->pcm)) == 0) {
+      /* This should be a stream error; it makes no sense for poll(2) to wake
+         for this stream and then have the stream report that it's not ready.
+         Unfortunately, this does happen, so just bail out and try again. */
+      pthread_mutex_unlock(&stm->mutex);
+      return RUNNING;
+    }
 
-  /* Failed to recover from an xrun, this stream must be broken. */
-  if (avail < 0) {
-    pthread_mutex_unlock(&stm->mutex);
-    stm->state_callback(stm, stm->user_ptr, CUBEB_STATE_ERROR);
-    return ERROR;
+    if (avail > 0)
+      break;
+    if (pipefailures++ > 11) {
+      fprintf(stderr, "%s: repeated failures from snd_pcm_avail_update, "
+              "giving up\n", __func__);
+      pthread_mutex_unlock(&stm->mutex);
+      stm->state_callback(stm, stm->user_ptr, CUBEB_STATE_ERROR);
+      return ERROR;
+    }
+    WRAP(snd_pcm_recover)(stm->pcm, avail, 1);
   }
+  pipefailures = againfailures = 0;
 
   /* This should never happen. */
   if ((unsigned int) avail > stm->buffer_size) {
@@ -294,8 +350,8 @@ alsa_refill_stream(cubeb_stream * stm)
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
@@ -303,7 +359,7 @@ alsa_refill_stream(cubeb_stream * stm)
     }
   }
 
-  p = calloc(1, snd_pcm_frames_to_bytes(stm->pcm, avail));
+  p = calloc(1, WRAP(snd_pcm_frames_to_bytes)(stm->pcm, avail));
   assert(p);
 
   pthread_mutex_unlock(&stm->mutex);
@@ -312,10 +368,11 @@ alsa_refill_stream(cubeb_stream * stm)
   if (got < 0) {
     pthread_mutex_unlock(&stm->mutex);
     stm->state_callback(stm, stm->user_ptr, CUBEB_STATE_ERROR);
+    free(p);
     return ERROR;
   }
   if (got > 0) {
-    snd_pcm_sframes_t wrote;
+    snd_pcm_sframes_t wrote, towrite = got;
 
     if (stm->params.format == CUBEB_SAMPLE_FLOAT32NE) {
       float * b = (float *) p;
@@ -328,14 +385,66 @@ alsa_refill_stream(cubeb_stream * stm)
         b[i] *= stm->volume;
       }
     }
-    wrote = snd_pcm_writei(stm->pcm, p, got);
-    if (wrote == -EPIPE) {
-      snd_pcm_recover(stm->pcm, wrote, 1);
-      wrote = snd_pcm_writei(stm->pcm, p, got);
-    }
-    assert(wrote >= 0 && wrote == got);
-    stm->write_position += wrote;
-    gettimeofday(&stm->last_activity, NULL);
+    for (;;) {
+      wrote = WRAP(snd_pcm_writei)(stm->pcm, p,
+        towrite > avail ? avail : towrite);
+      switch(wrote) {
+      case -EPIPE:
+        if (pipefailures++ > 3) {
+          fprintf(stderr, "%s: Too many underflows, giving up\n", __func__);
+          stm->state_callback(stm, stm->user_ptr, CUBEB_STATE_ERROR);
+          pthread_mutex_unlock(&stm->mutex);
+          free(p);
+          return ERROR;
+        }
+        WRAP(snd_pcm_recover)(stm->pcm, wrote, 1);
+        continue;
+      case -EAGAIN:
+        if (againfailures++ > 3) {
+          fprintf(stderr, "%s: Too many -EAGAIN errors from snd_pcm_writei, "
+	    "giving up\n", __func__);
+          stm->state_callback(stm, stm->user_ptr, CUBEB_STATE_ERROR);
+          pthread_mutex_unlock(&stm->mutex);
+          free(p);
+          return ERROR;
+        }
+        continue;
+#if __linux__
+      case -EBADFD:
+#else
+      case -EBADF:
+#endif
+        fprintf(stderr, "%s: snc_pcm_writei returned -%s, giving up\n",
+                __func__, "EBADFD");
+        free(p);
+        stm->state_callback(stm, stm->user_ptr, CUBEB_STATE_ERROR);
+        pthread_mutex_unlock(&stm->mutex);
+        return ERROR;
+      }
+      if (wrote < 0) {
+        fprintf(stderr, "%s: snc_pcm_writei returned unexpected error %lld, "
+                "giving up\n", __func__, (long long)wrote);
+        free(p);
+        stm->state_callback(stm, stm->user_ptr, CUBEB_STATE_ERROR);
+        pthread_mutex_unlock(&stm->mutex);
+        return ERROR;
+      }
+      pipefailures = againfailures = 0;
+      stm->write_position += wrote;
+      gettimeofday(&stm->last_activity, NULL);
+      if (wrote > towrite) {
+        fprintf(stderr, "%s: snc_pcm_writei wrote %lld frames, which was more "
+	        "than we requested (%lld). This should not happen, giving up\n",
+                __func__, (long long)wrote, (long long)towrite);
+        free(p);
+        stm->state_callback(stm, stm->user_ptr, CUBEB_STATE_ERROR);
+        pthread_mutex_unlock(&stm->mutex);
+        return ERROR;
+      }
+      if (towrite == wrote)
+        break;
+      towrite -= wrote;
+    }
   }
   if (got != avail) {
     long buffer_fill = stm->buffer_size - (avail - got);
@@ -343,7 +452,7 @@ alsa_refill_stream(cubeb_stream * stm)
 
     /* Fill the remaining buffer with silence to guarantee one full period
        has been written. */
-    snd_pcm_writei(stm->pcm, (char *) p + got, avail - got);
+    WRAP(snd_pcm_writei)(stm->pcm, (char *) p + got, avail - got);
 
     set_timeout(&stm->drain_timeout, buffer_time * 1000);
 
@@ -454,26 +563,26 @@ get_slave_pcm_node(snd_config_t * lconf,
 
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
@@ -482,7 +591,7 @@ get_slave_pcm_node(snd_config_t * lconf,
     if (r < 0 || r > (int) sizeof(node_name)) {
       break;
     }
-    r = snd_config_search(lconf, node_name, &pcm);
+    r = WRAP(snd_config_search)(lconf, node_name, &pcm);
     if (r < 0) {
       break;
     }
@@ -491,7 +600,7 @@ get_slave_pcm_node(snd_config_t * lconf,
   } while (0);
 
   if (slave_def) {
-    snd_config_delete(slave_def);
+    WRAP(snd_config_delete)(slave_def);
   }
 
   return NULL;
@@ -514,22 +623,22 @@ init_local_config_with_workaround(char c
 
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
@@ -538,7 +647,7 @@ init_local_config_with_workaround(char c
     if (r < 0 || r > (int) sizeof(node_name)) {
       break;
     }
-    r = snd_config_search(lconf, node_name, &pcm_node);
+    r = WRAP(snd_config_search)(lconf, node_name, &pcm_node);
     if (r < 0) {
       break;
     }
@@ -549,12 +658,12 @@ init_local_config_with_workaround(char c
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
@@ -565,18 +674,18 @@ init_local_config_with_workaround(char c
 
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
@@ -584,7 +693,7 @@ init_local_config_with_workaround(char c
     return lconf;
   } while (0);
 
-  snd_config_delete(lconf);
+  WRAP(snd_config_delete)(lconf);
 
   return NULL;
 }
@@ -596,9 +705,9 @@ alsa_locked_pcm_open(snd_pcm_t ** pcm, s
 
   pthread_mutex_lock(&cubeb_alsa_mutex);
   if (local_config) {
-    r = snd_pcm_open_lconf(pcm, CUBEB_ALSA_PCM_NAME, stream, SND_PCM_NONBLOCK, local_config);
+    r = WRAP(snd_pcm_open_lconf)(pcm, CUBEB_ALSA_PCM_NAME, stream, SND_PCM_NONBLOCK, local_config);
   } else {
-    r = snd_pcm_open(pcm, CUBEB_ALSA_PCM_NAME, stream, SND_PCM_NONBLOCK);
+    r = WRAP(snd_pcm_open)(pcm, CUBEB_ALSA_PCM_NAME, stream, SND_PCM_NONBLOCK);
   }
   pthread_mutex_unlock(&cubeb_alsa_mutex);
 
@@ -611,7 +720,7 @@ alsa_locked_pcm_close(snd_pcm_t * pcm)
   int r;
 
   pthread_mutex_lock(&cubeb_alsa_mutex);
-  r = snd_pcm_close(pcm);
+  r = WRAP(snd_pcm_close)(pcm);
   pthread_mutex_unlock(&cubeb_alsa_mutex);
 
   return r;
@@ -668,12 +777,65 @@ alsa_init(cubeb ** context, char const *
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
@@ -681,6 +843,8 @@ alsa_init(cubeb ** context, char const *
   ctx = calloc(1, sizeof(*ctx));
   assert(ctx);
 
+  ctx->libasound = libasound;
+
   ctx->ops = &alsa_ops;
 
   r = pthread_mutex_init(&ctx->mutex, NULL);
@@ -730,7 +894,7 @@ alsa_init(cubeb ** context, char const *
        config fails with EINVAL, the PA PCM is too old for this workaround. */
     if (r == -EINVAL) {
       pthread_mutex_lock(&cubeb_alsa_mutex);
-      snd_config_delete(ctx->local_config);
+      WRAP(snd_config_delete)(ctx->local_config);
       pthread_mutex_unlock(&cubeb_alsa_mutex);
       ctx->local_config = NULL;
     } else if (r >= 0) {
@@ -769,9 +933,13 @@ alsa_destroy(cubeb * ctx)
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
 
@@ -839,7 +1007,7 @@ alsa_stream_init(cubeb * ctx, cubeb_stre
     return CUBEB_ERROR;
   }
 
-  r = snd_pcm_nonblock(stm->pcm, 1);
+  r = WRAP(snd_pcm_nonblock)(stm->pcm, 1);
   assert(r == 0);
 
   /* Ugly hack: the PA ALSA plugin allows buffer configurations that can't
@@ -849,23 +1017,23 @@ alsa_stream_init(cubeb * ctx, cubeb_stre
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
@@ -896,7 +1064,7 @@ alsa_stream_destroy(cubeb_stream * stm)
   pthread_mutex_lock(&stm->mutex);
   if (stm->pcm) {
     if (stm->state == DRAINING) {
-      snd_pcm_drain(stm->pcm);
+      WRAP(snd_pcm_drain)(stm->pcm);
     }
     alsa_locked_pcm_close(stm->pcm);
     stm->pcm = NULL;
@@ -906,7 +1074,10 @@ alsa_stream_destroy(cubeb_stream * stm)
   pthread_mutex_destroy(&stm->mutex);
 
   r = pthread_cond_destroy(&stm->cond);
-  assert(r == 0);
+  if (r != 0) {	/* XXX stopgap until someone figures out the real reason */
+    fprintf(stderr,"alsa_stream_destroy: pthread_cond_destroy failed: %s",
+      strerror(r));
+  }
 
   alsa_unregister_stream(stm);
 
@@ -938,12 +1109,12 @@ alsa_get_max_channel_count(cubeb * ctx, 
     return CUBEB_ERROR;
   }
 
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
@@ -963,34 +1134,34 @@ alsa_get_preferred_sample_rate(cubeb * c
 
   /* get a pcm, disabling resampling, so we get a rate the
    * hardware/dmix/pulse/etc. supports. */
-  r = snd_pcm_open(&pcm, CUBEB_ALSA_PCM_NAME, SND_PCM_STREAM_PLAYBACK | SND_PCM_NO_AUTO_RESAMPLE, 0);
+  r = WRAP(snd_pcm_open)(&pcm, CUBEB_ALSA_PCM_NAME, SND_PCM_STREAM_PLAYBACK | SND_PCM_NO_AUTO_RESAMPLE, 0);
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
@@ -1014,7 +1185,7 @@ alsa_stream_start(cubeb_stream * stm)
   ctx = stm->context;
 
   pthread_mutex_lock(&stm->mutex);
-  snd_pcm_pause(stm->pcm, 0);
+  WRAP(snd_pcm_pause)(stm->pcm, 0);
   gettimeofday(&stm->last_activity, NULL);
   pthread_mutex_unlock(&stm->mutex);
 
@@ -1048,7 +1219,7 @@ alsa_stream_stop(cubeb_stream * stm)
   pthread_mutex_unlock(&ctx->mutex);
 
   pthread_mutex_lock(&stm->mutex);
-  snd_pcm_pause(stm->pcm, 1);
+  WRAP(snd_pcm_pause)(stm->pcm, 1);
   pthread_mutex_unlock(&stm->mutex);
 
   return CUBEB_OK;
@@ -1064,14 +1235,17 @@ alsa_stream_get_position(cubeb_stream * 
   pthread_mutex_lock(&stm->mutex);
 
   delay = -1;
-  if (snd_pcm_state(stm->pcm) != SND_PCM_STATE_RUNNING ||
-      snd_pcm_delay(stm->pcm, &delay) != 0) {
+  if (WRAP(snd_pcm_state)(stm->pcm) != SND_PCM_STATE_RUNNING ||
+      WRAP(snd_pcm_delay)(stm->pcm, &delay) != 0) {
     *position = stm->last_position;
     pthread_mutex_unlock(&stm->mutex);
     return CUBEB_OK;
   }
 
-  assert(delay >= 0);
+  if (delay < 0) {
+    WRAP(snd_pcm_forward)(stm->pcm, -delay);
+    delay = 0;
+  }
 
   *position = 0;
   if (stm->write_position >= (snd_pcm_uframes_t) delay) {
@@ -1090,7 +1264,7 @@ alsa_stream_get_latency(cubeb_stream * s
   snd_pcm_sframes_t delay;
   /* This function returns the delay in frames until a frame written using
      snd_pcm_writei is sent to the DAC. The DAC delay should be < 1ms anyways. */
-  if (snd_pcm_delay(stm->pcm, &delay)) {
+  if (WRAP(snd_pcm_delay)(stm->pcm, &delay)) {
     return CUBEB_ERROR;
   }
 
