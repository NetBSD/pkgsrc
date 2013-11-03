$NetBSD: patch-media_webrtc_signaling_src_sipcc_cpr_darwin_cpr__darwin__ipc.c,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- media/webrtc/signaling/src/sipcc/cpr/darwin/cpr_darwin_ipc.c.orig	2013-05-11 19:19:44.000000000 +0000
+++ media/webrtc/signaling/src/sipcc/cpr/darwin/cpr_darwin_ipc.c
@@ -322,11 +322,15 @@ cprGetMessage (cprMsgQueue_t msgQueue, b
     cpr_msgq_node_t *node;
 	struct timespec timeout;
 	struct timeval tv;
+#ifndef __APPLE__
+	struct timezone tz;
+#else
 	// On the iPhone, there is a DarwinAlias problem with "timezone"
 	struct _timezone {
 		int     tz_minuteswest; /* of Greenwich */
 		int     tz_dsttime;     /* type of dst correction to apply */
 	} tz;
+#endif
 
     /* Initialize ppUserData */
     if (ppUserData) {
