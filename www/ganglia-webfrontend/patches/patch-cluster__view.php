$NetBSD: patch-cluster__view.php,v 1.1 2018/09/21 14:48:08 bacon Exp $

# Fix cluster_view display issue
--- cluster_view.php.orig	2018-09-20 15:05:53.000000000 +0000
+++ cluster_view.php
@@ -23,7 +23,7 @@ if ($refresh) {
 }
 
 function get_picker_metrics($metrics, $reports, $gweb_root, $graph_engine) {
-  $context_metrics = "";
+  $context_metrics = array();
   if (count($metrics)) {
     foreach ($metrics as $host_metrics) {
       foreach ($host_metrics as $metric_name => $metric_value) {
