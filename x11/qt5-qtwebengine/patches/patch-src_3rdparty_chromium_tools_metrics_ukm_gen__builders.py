$NetBSD: patch-src_3rdparty_chromium_tools_metrics_ukm_gen__builders.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/tools/metrics/ukm/gen_builders.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/tools/metrics/ukm/gen_builders.py
@@ -48,9 +48,10 @@ def ReadFilteredData(path):
     data = ukm_model.UKM_XML_TYPE.Parse(ukm_file.read())
     event_tag = ukm_model._EVENT_TYPE.tag
     metric_tag = ukm_model._METRIC_TYPE.tag
-    data[event_tag] = filter(ukm_model.IsNotObsolete, data[event_tag])
+    data[event_tag] = list(filter(ukm_model.IsNotObsolete, data[event_tag]))
     for event in data[event_tag]:
-      event[metric_tag] = filter(ukm_model.IsNotObsolete, event[metric_tag])
+      event[metric_tag] = list(
+          filter(ukm_model.IsNotObsolete, event[metric_tag]))
     return data
 
 
