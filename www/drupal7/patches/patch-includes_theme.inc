$NetBSD: patch-includes_theme.inc,v 1.1 2018/10/03 10:58:15 prlw1 Exp $

Issue #2885610
Avoid count() calls on uncountable variables
commit 73e12f0ddf1ed60c13331dc3a9b8ea16d1599307

Issue #2996519
PHP 7.2 compatibility - make sure some variables are arrays in
theme_links()
commit 083a4eca4a2ebc5276eed2f11fc4a595b07898ba

--- includes/theme.inc.orig	2018-10-03 09:32:02.932500773 +0000
+++ includes/theme.inc
@@ -1776,8 +1776,8 @@ function theme_link($variables) {
  *     http://www.w3.org/TR/WCAG-TECHS/H42.html for more information.
  */
 function theme_links($variables) {
-  $links = $variables['links'];
-  $attributes = $variables['attributes'];
+  $links = (array) $variables['links'];
+  $attributes = (array) $variables['attributes'];
   $heading = $variables['heading'];
   global $language_url;
   $output = '';
@@ -1995,7 +1995,7 @@ function theme_table($variables) {
   $empty = $variables['empty'];
 
   // Add sticky headers, if applicable.
-  if (count($header) && $sticky) {
+  if (!empty($header) && $sticky) {
     drupal_add_js('misc/tableheader.js');
     // Add 'sticky-enabled' class to the table to identify it for JS.
     // This is needed to target tables constructed by this function.
@@ -2009,7 +2009,7 @@ function theme_table($variables) {
   }
 
   // Format the table columns:
-  if (count($colgroups)) {
+  if (!empty($colgroups)) {
     foreach ($colgroups as $number => $colgroup) {
       $attributes = array();
 
@@ -2044,38 +2044,40 @@ function theme_table($variables) {
   }
 
   // Add the 'empty' row message if available.
-  if (!count($rows) && $empty) {
+  if (empty($rows) && $empty) {
     $header_count = 0;
-    foreach ($header as $header_cell) {
-      if (is_array($header_cell)) {
-        $header_count += isset($header_cell['colspan']) ? $header_cell['colspan'] : 1;
-      }
-      else {
-        $header_count++;
+    if (!empty($header)) {
+      foreach ($header as $header_cell) {
+        if (is_array($header_cell)) {
+          $header_count += isset($header_cell['colspan']) ? $header_cell['colspan'] : 1;
+        }
+        else {
+          $header_count++;
+        }
       }
     }
     $rows[] = array(array('data' => $empty, 'colspan' => $header_count, 'class' => array('empty', 'message')));
   }
 
   // Format the table header:
-  if (count($header)) {
+  if (!empty($header)) {
     $ts = tablesort_init($header);
     // HTML requires that the thead tag has tr tags in it followed by tbody
     // tags. Using ternary operator to check and see if we have any rows.
-    $output .= (count($rows) ? ' <thead><tr>' : ' <tr>');
+    $output .= (!empty($rows) ? ' <thead><tr>' : ' <tr>');
     foreach ($header as $cell) {
       $cell = tablesort_header($cell, $header, $ts);
       $output .= _theme_table_cell($cell, TRUE);
     }
     // Using ternary operator to close the tags based on whether or not there are rows
-    $output .= (count($rows) ? " </tr></thead>\n" : "</tr>\n");
+    $output .= (!empty($rows) ? " </tr></thead>\n" : "</tr>\n");
   }
   else {
     $ts = array();
   }
 
   // Format the table rows:
-  if (count($rows)) {
+  if (!empty($rows)) {
     $output .= "<tbody>\n";
     $flip = array('even' => 'odd', 'odd' => 'even');
     $class = 'even';
@@ -2095,7 +2097,7 @@ function theme_table($variables) {
         $attributes = array();
         $no_striping = FALSE;
       }
-      if (count($cells)) {
+      if (!empty($cells)) {
         // Add odd/even class
         if (!$no_striping) {
           $class = $flip[$class];
