$NetBSD: patch-Xtransint.h,v 1.1 2013/11/07 22:50:50 wiz Exp $

--- Xtransint.h.orig	2013-11-07 06:58:43.000000000 +0000
+++ Xtransint.h
@@ -291,6 +291,7 @@ typedef struct _Xtransport {
 	int			/* size */
     );
 
+#if XTRANS_SEND_FDS
     int (*SendFd)(
 	XtransConnInfo,		/* connection */
         int,                    /* fd */
@@ -300,6 +301,7 @@ typedef struct _Xtransport {
     int (*RecvFd)(
 	XtransConnInfo		/* connection */
     );
+#endif
 
     int	(*Disconnect)(
 	XtransConnInfo		/* connection */
