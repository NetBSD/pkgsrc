$NetBSD: patch-include_ap_mmn.h,v 1.1 2015/11/12 15:21:51 prlw1 Exp $

Fix a regression with 2.2.31 that caused inherited workers to
use a different scoreboard slot then the original one.

https://svn.apache.org/viewvc?view=revision&revision=1700408

--- include/ap_mmn.h.orig	2015-06-05 16:50:47.000000000 +0000
+++ include/ap_mmn.h
@@ -158,6 +158,8 @@
  * 20051115.38 (2.2.30) Add ap_proxy_set_scoreboard_lb() in mod_proxy.h
  * 20051115.39 (2.2.30) Add ap_proxy_connection_reusable()
  * 20051115.40 (2.2.30) Add ap_map_http_request_error()
+ * 20051115.41 (2.2.32) Add s member to proxy_server_conf struct and server
+ *                      member to proxy_worker struct.
  */
 
 #define MODULE_MAGIC_COOKIE 0x41503232UL /* "AP22" */
@@ -165,7 +167,7 @@
 #ifndef MODULE_MAGIC_NUMBER_MAJOR
 #define MODULE_MAGIC_NUMBER_MAJOR 20051115
 #endif
-#define MODULE_MAGIC_NUMBER_MINOR 40                    /* 0...n */
+#define MODULE_MAGIC_NUMBER_MINOR 41                    /* 0...n */
 
 /**
  * Determine if the server's current MODULE_MAGIC_NUMBER is at least a
