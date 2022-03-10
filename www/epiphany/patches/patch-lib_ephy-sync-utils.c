$NetBSD: patch-lib_ephy-sync-utils.c,v 1.2 2022/03/10 21:28:03 prlw1 Exp $

NetBSD does not have getrandom().

--- lib/ephy-sync-utils.c.orig	2021-12-21 00:24:23.810496800 +0000
+++ lib/ephy-sync-utils.c
@@ -32,7 +32,7 @@
 #include <string.h>
 #if defined(__linux__)
 #include <sys/random.h>
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <unistd.h>
 #endif
 
@@ -187,7 +187,7 @@ ephy_sync_utils_generate_random_bytes (v
   if (getentropy (out, num_bytes) == -1) {
     g_error ("Failed to get entropy: %s", g_strerror (errno));
   }
-#else
+#elif !defined(__NetBSD__)
   do {
     ret = getrandom (out, num_bytes, 0);
   } while (ret < (gssize)num_bytes && errno == EINTR);
