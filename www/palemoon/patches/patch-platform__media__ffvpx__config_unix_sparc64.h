--- platform/media/ffvpx/config_unix_sparc64.h.orig	2025-12-04 01:58:30.149543083 +0100
+++ platform/media/ffvpx/config_unix_sparc64.h	2025-12-04 09:40:20.979988277 +0100
@@ -332,10 +332,19 @@
 #define HAVE_NANOSLEEP 1
 #define HAVE_PEEKNAMEDPIPE 0
 #define HAVE_POSIX_MEMALIGN 1
+#if defined(__linux__)
 #define HAVE_PRCTL 1
+#else
+#define HAVE_PRCTL 0
+#endif
 #define HAVE_PTHREAD_CANCEL 1
-#define HAVE_PTHREAD_SET_NAME_NP 0
+#if defined(__NetBSD__)
+#define HAVE_PTHREAD_SET_NAME_NP 1
 #define HAVE_PTHREAD_SETNAME_NP 1
+#else
+#define HAVE_PTHREAD_SET_NAME_NP 0
+#define HAVE_PTHREAD_SETNAME_NP 0
+#endif
 #define HAVE_SCHED_GETAFFINITY 0
 #define HAVE_SECITEMIMPORT 0
 #define HAVE_SETCONSOLETEXTATTRIBUTE 0
