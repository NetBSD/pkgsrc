$NetBSD: patch-src_fdevent__solaris__port.c,v 1.3 2019/11/11 19:47:10 nros Exp $
* fix build on illumos
  from upstream: https://redmine.lighttpd.net/issues/2959
--- src/fdevent_solaris_port.c.orig	2019-11-11 18:06:14.250349299 +0000
+++ src/fdevent_solaris_port.c
@@ -20,7 +20,7 @@ static int fdevent_solaris_port_event_de
 }
 
 static int fdevent_solaris_port_event_set(fdevents *ev, fdnode *fdn, int events) {
-    int fd = fdn->fdn_ndx = fdn->fd;
+    int fd = fdn->fde_ndx = fdn->fd;
     intptr_t ud = events & (POLLIN|POLLOUT);
     return port_associate(ev->port_fd,PORT_SOURCE_FD,fd,(int)ud,(void*)ud);
 }
