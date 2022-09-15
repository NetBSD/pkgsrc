$NetBSD: patch-inc_ui_principal-edit.php,v 1.1 2022/09/15 12:59:16 hauke Exp $

PHP 8.1 mandates globals be declared.
Fixes <https://gitlab.com/davical-project/davical/-/issues/271>

--- inc/ui/principal-edit.php.orig	2021-03-01 13:24:48.000000000 +0000
+++ inc/ui/principal-edit.php
@@ -180,6 +180,7 @@ function handle_subaction( $subaction ) 
 
 function principal_editor() {
   global $c, $id, $can_write_principal, $session;
+  global $privilege_names;
   $editor = new Editor(translate('Principal'), 'dav_principal');
 
   $editor->SetLookup( 'date_format_type', "SELECT 'E', 'European' UNION SELECT 'U', 'US Format' UNION SELECT 'I', 'ISO Format'" );
