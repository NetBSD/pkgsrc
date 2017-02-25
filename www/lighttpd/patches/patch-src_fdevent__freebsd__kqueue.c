$NetBSD: patch-src_fdevent__freebsd__kqueue.c,v 1.1.2.2 2017/02/25 09:18:10 bsiegert Exp $

Apply fix from https://redmine.lighttpd.net/issues/2788,
ref. request from Glenn Strauss.

--- src/fdevent_freebsd_kqueue.c.orig	2017-01-14 05:05:17.000000000 +0000
+++ src/fdevent_freebsd_kqueue.c
@@ -75,14 +75,14 @@ static int fdevent_freebsd_kqueue_event_
 	if (events == oevents) return fd;
 
 	if (addevents & FDEVENT_IN)  {
-		EV_SET(&kev[n], fd, EVFILT_READ, EV_ADD|EV_CLEAR, 0, 0, NULL);
+		EV_SET(&kev[n], fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
 		n++;
 	} else if (delevents & FDEVENT_IN) {
 		EV_SET(&kev[n], fd, EVFILT_READ, EV_DELETE, 0, 0, NULL);
 		n++;
 	}
 	if (addevents & FDEVENT_OUT)  {
-		EV_SET(&kev[n], fd, EVFILT_WRITE, EV_ADD|EV_CLEAR, 0, 0, NULL);
+		EV_SET(&kev[n], fd, EVFILT_WRITE, EV_ADD, 0, 0, NULL);
 		n++;
 	} else if (delevents & FDEVENT_OUT) {
 		EV_SET(&kev[n], fd, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
