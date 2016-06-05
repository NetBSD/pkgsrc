$NetBSD: patch-config.php,v 1.1 2016/06/05 00:02:21 jym Exp $

Use the correct path for the Z-push state directory.

--- config.php.orig	2016-05-04 23:37:41.000000000 +0000
+++ config.php
@@ -72,7 +72,7 @@
 /**********************************************************************************
  *  Default FileStateMachine settings
  */
-    define('STATE_DIR', '/var/lib/z-push/');
+    define('STATE_DIR', '@ZPUSHSTATEDIR@');
 
 
 /**********************************************************************************
@@ -282,4 +282,4 @@
 */
     );
 
-?>
\ No newline at end of file
+?>
