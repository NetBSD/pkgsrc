$NetBSD: patch-os_xsha1.c,v 1.1 2026/05/24 10:12:27 tnn Exp $

- handle nettle 4 API change

--- os/xsha1.c.orig	2026-05-24 09:00:16.266998201 +0000
+++ os/xsha1.c
@@ -152,7 +152,7 @@ x_sha1_final(void *ctx, unsigned char re
 
 #elif defined(HAVE_SHA1_IN_LIBNETTLE)   /* Use libnettle for SHA1 */
 
-#include <nettle/sha.h>
+#include <nettle/sha1.h>
 
 void *
 x_sha1_init(void)
@@ -175,7 +175,7 @@ x_sha1_update(void *ctx, void *data, int
 int
 x_sha1_final(void *ctx, unsigned char result[20])
 {
-    sha1_digest(ctx, 20, result);
+    sha1_digest(ctx, result);
     free(ctx);
     return 1;
 }
