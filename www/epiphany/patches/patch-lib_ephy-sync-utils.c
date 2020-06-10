$NetBSD: patch-lib_ephy-sync-utils.c,v 1.1 2020/06/10 19:45:51 nia Exp $

NetBSD does not have getrandom().

--- lib/ephy-sync-utils.c.orig	2020-05-29 15:32:59.180212500 +0000
+++ lib/ephy-sync-utils.c
@@ -30,7 +30,11 @@
 #include <libsoup/soup.h>
 #include <stdio.h>
 #include <string.h>
+#ifndef __NetBSD__
 #include <sys/random.h>
+#else
+#include <stdlib.h>
+#endif
 
 static const char hex_digits[] = "0123456789abcdef";
 
@@ -179,12 +183,16 @@ ephy_sync_utils_generate_random_bytes (v
   g_assert (num_bytes > 0);
   g_assert (out);
 
+#ifndef __NetBSD__
   do {
     ret = getrandom (out, num_bytes, 0);
   } while (ret < (gssize)num_bytes && errno == EINTR);
 
   if (ret != (gssize)num_bytes)
     g_error ("Failed to generate randomness: %s", g_strerror (errno));
+#else
+  arc4random_buf (out, num_bytes);
+#endif
 }
 
 char *
