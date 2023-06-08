$NetBSD: patch-src_3rdparty_chromium_tools_metrics_ukm_ukm__model.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/tools/metrics/ukm/ukm_model.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/tools/metrics/ukm/ukm_model.py
@@ -42,7 +42,7 @@ _INDEX_TYPE = models.ObjectNodeType(
 _STATISTICS_TYPE =  models.ObjectNodeType(
     'statistics',
     attributes=[
-      ('export', str, r'^(?i)(|true|false)$'),
+      ('export', str, r'(?i)^(|true|false)$'),
     ],
     children=[
         models.ChildType(_QUANTILES_TYPE.tag, _QUANTILES_TYPE, multiple=False),
@@ -94,7 +94,7 @@ _EVENT_TYPE =  models.ObjectNodeType(
     'event',
     attributes=[
       ('name', str, r'^[A-Za-z0-9.]+$'),
-      ('singular', str, r'^(?i)(|true|false)$'),
+      ('singular', str, r'(?i)^(|true|false)$'),
     ],
     alphabetization=[
         (_OBSOLETE_TYPE.tag, _KEEP_ORDER),
