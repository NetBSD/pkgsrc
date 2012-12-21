$NetBSD: patch-includes_path.inc,v 1.1.2.2 2012/12/21 11:01:33 tron Exp $

Possible fix to SA4931.

--- includes/path.inc.orig	2012-12-19 18:51:43.000000000 +0000
+++ includes/path.inc
@@ -13,7 +13,7 @@
  * Initialize the $_GET['q'] variable to the proper normal path.
  */
 function drupal_init_path() {
-  if (!empty($_GET['q'])) {
+  if (!empty($_GET['q']) && is_string($_GET['q'])) {
     $_GET['q'] = drupal_get_normal_path(trim($_GET['q'], '/'));
   }
   else {
