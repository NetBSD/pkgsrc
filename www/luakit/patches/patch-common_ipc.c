$NetBSD: patch-common_ipc.c,v 1.1 2020/10/04 18:16:42 nia Exp $

[PATCH] Handle EOF sent to G_IO_IN instead of G_IO_HUP (NetBSD/OSX)

Fixes https://github.com/luakit/luakit/issues/725

--- common/ipc.c.orig	2020-09-19 10:55:41.000000000 +0000
+++ common/ipc.c
@@ -21,6 +21,7 @@
 #include "common/lualib.h"
 #include "common/luaserialize.h"
 #include "common/ipc.h"
+#include "log.h"
 
 /* Prototypes for ipc_recv_... functions */
 #define X(name) void ipc_recv_##name(ipc_endpoint_t *ipc, const void *msg, guint length);
@@ -138,6 +139,19 @@ ipc_recv_and_dispatch_or_enqueue(ipc_end
         case G_IO_STATUS_AGAIN:
             return;
         case G_IO_STATUS_EOF:
+            verbose("g_io_channel_read_chars(): End Of File received");
+            /* OSX and NetBSD are sending EOF on nonblocking channels first.
+             * These requests can be ignored. They should end up in
+             * recv_hup(), but unfortunately they do not.
+             *
+             * If we do not close the socket, glib will continue to
+             * call the G_IO_IN handler.
+             *
+             * We decrement the refcount to 1 here, and when ipc_recv
+             * decrements the refcount to zero, the socket will be
+             * disconnected.
+             */
+            g_atomic_int_dec_and_test(&ipc->refcount);
             return;
         case G_IO_STATUS_ERROR:
             if (!g_str_equal(ipc->name, "UI"))
