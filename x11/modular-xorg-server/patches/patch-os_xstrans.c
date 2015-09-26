$NetBSD: patch-os_xstrans.c,v 1.1 2015/09/26 18:35:41 tnn Exp $

CMSG_SPACE must evaluate to a constant, but doesn't on netbsd-5.
See sys/socket.h r1.104.

--- os/xstrans.c.orig	2015-05-21 14:23:54.000000000 +0000
+++ os/xstrans.c
@@ -14,4 +14,13 @@ _X_ATTRIBUTE_PRINTF(1, 2);
 #define TRANS_REOPEN
 #define TRANS_SERVER
 #define XSERV_t
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if (__NetBSD_Version__ < 600000000)
+#include <sys/socket.h>
+#define __MY_CMSG_ALIGN(n) (((n) + 7) & ~7)
+#undef  CMSG_SPACE
+#define CMSG_SPACE(l) (__MY_CMSG_ALIGN(sizeof(struct msghdr)) + __MY_CMSG_ALIGN(l))
+#endif
+#endif
 #include <X11/Xtrans/transport.c>
