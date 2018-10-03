$NetBSD: patch-includes_bootstrap.inc,v 1.1 2018/10/03 10:58:15 prlw1 Exp $

Issue #2925449
Function each() is deprecated since PHP 7.2
commit 28de6772813387bf02a4bf6f75b9119c4c20a3f4

--- includes/bootstrap.inc.orig	2018-04-25 15:32:27.000000000 +0000
+++ includes/bootstrap.inc
@@ -3785,8 +3785,12 @@ function _drupal_shutdown_function() {
   chdir(DRUPAL_ROOT);
 
   try {
-    while (list($key, $callback) = each($callbacks)) {
+    // Manually iterate over the array instead of using a foreach loop.
+    // A foreach operates on a copy of the array, so any shutdown functions that
+    // were added from other shutdown functions would never be called.
+    while ($callback = current($callbacks)) {
       call_user_func_array($callback['callback'], $callback['arguments']);
+      next($callbacks);
     }
   }
   catch (Exception $exception) {
