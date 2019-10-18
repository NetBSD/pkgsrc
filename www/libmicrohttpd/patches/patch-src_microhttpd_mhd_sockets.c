$NetBSD: patch-src_microhttpd_mhd_sockets.c,v 1.1 2019/10/18 08:36:19 ng0 Exp $

pick commit 093c83c2270e18294811f394c9af87a2cb56ea20
as it adds a missing return on systems which do have
TCP_CORK or TCP_NOPUSH.

--- src/microhttpd/mhd_sockets.c~
+++ src/microhttpd/mhd_sockets.c
@@ -530,6 +530,8 @@ MHD_socket_cork_ (MHD_socket sock,
       return 0; /* even force flush failed!? */
     return 1; /* success */
   }
+#else
+  return 1; /* success */
 #endif
 #else
   /* do not have MHD_TCP_CORK_NOPUSH at all */
