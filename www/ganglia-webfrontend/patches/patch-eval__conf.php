$NetBSD: patch-eval__conf.php,v 1.1 2016/02/16 13:05:23 fhajny Exp $

Assert proper paths.

--- eval_conf.php.orig	2015-04-12 00:04:33.000000000 +0000
+++ eval_conf.php
@@ -13,8 +13,8 @@ require_once 'lib/GangliaAcl.php';
 require_once 'lib/GangliaAuth.php';
 
 # Include user-defined overrides if they exist.
-if( file_exists( $base_dir . "/conf.php" ) ) {
-  include_once $base_dir . "/conf.php";
+if( file_exists( "@PKG_SYSCONFDIR@/conf.php" ) ) {
+  include_once "@PKG_SYSCONFDIR@/conf.php";
 }
 
 $errors = array();
