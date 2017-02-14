$NetBSD: patch-src_event_modules_ngx__eventport__module.c,v 1.1 2017/02/14 10:10:55 fhajny Exp $

Fix a situation where Nginx can stop servicing events when port_getn() returns a timeout.

https://github.com/joyent/nginx/commit/bdd0c625236bc25799bd6f81dcf5d774928e8cb0

--- src/event/modules/ngx_eventport_module.c.orig	2017-01-24 14:02:19.000000000 +0000
+++ src/event/modules/ngx_eventport_module.c
@@ -468,6 +468,16 @@ ngx_eventport_process_events(ngx_cycle_t
         ngx_time_update();
     }
 
+    /*
+     * There's a long standing condition with event ports that port_getn() may
+     * return ETIME even when events are available. This would happen if we have
+     * specified a timeout to port_getn() without reaching the number of
+     * requested events.
+     */
+    if (n == -1 && err == ETIME && events > 0) {
+	    n = 0;
+    }
+
     if (n == -1) {
         if (err == ETIME) {
             if (timer != NGX_TIMER_INFINITE) {
