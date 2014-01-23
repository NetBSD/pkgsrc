$NetBSD: patch-src_fdevent_poll.c,v 1.1 2014/01/23 13:20:12 adam Exp $

Error fix.

--- src/fdevent_poll.c.orig	2014-01-23 11:58:57.000000000 +0000
+++ src/fdevent_poll.c
@@ -193,7 +193,7 @@ int fdevent_poll_init(fdevents *ev) {
 int fdevent_poll_init(fdevents *ev) {
 	UNUSED(ev);
 
-	log_error_write(srv, __FILE__, __LINE__,
+	log_error_write(ev->srv, __FILE__, __LINE__,
 		"s", "poll is not supported, try to set server.event-handler = \"select\"");
 
 	return -1;
