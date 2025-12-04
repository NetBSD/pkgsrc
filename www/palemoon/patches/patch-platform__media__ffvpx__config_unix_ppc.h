--- platform/media/ffvpx/config_unix_ppc.h.orig	2025-10-15 19:46:52.000000000 +0200
+++ platform/media/ffvpx/config_unix_ppc.h	2025-12-04 09:40:13.469799012 +0100
@@ -339,10 +339,19 @@
 #define HAVE_NANOSLEEP 1
 #define HAVE_PEEKNAMEDPIPE 0
 #define HAVE_POSIX_MEMALIGN 1
+#if defined(__linux__)
 #define HAVE_PRCTL 1
+#else
+#define HAVE_PRCTL 0
+#endif
 #define HAVE_PTHREAD_CANCEL 1
+#if defined(__NetBSD__)
+#define HAVE_PTHREAD_SET_NAME_NP 1
+#define HAVE_PTHREAD_SETNAME_NP 1
+#else
 #define HAVE_PTHREAD_SET_NAME_NP 0
 #define HAVE_PTHREAD_SETNAME_NP 0
+#endif
 #define HAVE_SCHED_GETAFFINITY 1
 #define HAVE_SECITEMIMPORT 0
 #define HAVE_SETCONSOLETEXTATTRIBUTE 0
