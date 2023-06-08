$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_v8__utilities.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/v8_utilities.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/v8_utilities.py
@@ -271,7 +271,7 @@ EXPOSED_WORKERS = set([
 ])
 
 
-class ExposureSet:
+class ExposureSet(object):
     """An ExposureSet is a collection of Exposure instructions."""
 
     def __init__(self, exposures=None):
