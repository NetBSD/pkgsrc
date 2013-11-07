$NetBSD: patch-Xtranssock.c,v 1.1 2013/11/07 22:50:50 wiz Exp $

--- Xtranssock.c.orig	2013-11-03 02:12:32.000000000 +0000
+++ Xtranssock.c
@@ -2506,8 +2506,10 @@ Xtransport	TRANS(SocketTCPFuncs) = {
 	TRANS(SocketWrite),
 	TRANS(SocketReadv),
 	TRANS(SocketWritev),
+#if XTRANS_SEND_FDS
         TRANS(SocketSendFdInvalid),
         TRANS(SocketRecvFdInvalid),
+#endif
 	TRANS(SocketDisconnect),
 	TRANS(SocketINETClose),
 	TRANS(SocketINETClose),
@@ -2548,8 +2550,10 @@ Xtransport	TRANS(SocketINETFuncs) = {
 	TRANS(SocketWrite),
 	TRANS(SocketReadv),
 	TRANS(SocketWritev),
+#if XTRANS_SEND_FDS
         TRANS(SocketSendFdInvalid),
         TRANS(SocketRecvFdInvalid),
+#endif
 	TRANS(SocketDisconnect),
 	TRANS(SocketINETClose),
 	TRANS(SocketINETClose),
@@ -2591,8 +2595,10 @@ Xtransport     TRANS(SocketINET6Funcs) =
 	TRANS(SocketWrite),
 	TRANS(SocketReadv),
 	TRANS(SocketWritev),
+#if XTRANS_SEND_FDS
         TRANS(SocketSendFdInvalid),
         TRANS(SocketRecvFdInvalid),
+#endif
 	TRANS(SocketDisconnect),
 	TRANS(SocketINETClose),
 	TRANS(SocketINETClose),
@@ -2641,8 +2647,10 @@ Xtransport	TRANS(SocketLocalFuncs) = {
 	TRANS(SocketWrite),
 	TRANS(SocketReadv),
 	TRANS(SocketWritev),
+#if XTRANS_SEND_FDS
         TRANS(SocketSendFd),
         TRANS(SocketRecvFd),
+#endif
 	TRANS(SocketDisconnect),
 	TRANS(SocketUNIXClose),
 	TRANS(SocketUNIXCloseForCloning),
@@ -2697,8 +2705,10 @@ Xtransport	TRANS(SocketUNIXFuncs) = {
 	TRANS(SocketWrite),
 	TRANS(SocketReadv),
 	TRANS(SocketWritev),
+#if XTRANS_SEND_FDS
         TRANS(SocketSendFd),
         TRANS(SocketRecvFd),
+#endif
 	TRANS(SocketDisconnect),
 	TRANS(SocketUNIXClose),
 	TRANS(SocketUNIXCloseForCloning),
