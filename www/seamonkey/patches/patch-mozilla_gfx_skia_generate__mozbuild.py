$NetBSD: patch-mozilla_gfx_skia_generate__mozbuild.py,v 1.2 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/gfx/skia/generate_mozbuild.py.orig	2015-09-25 07:36:46.000000000 +0000
+++ mozilla/gfx/skia/generate_mozbuild.py
@@ -144,6 +144,12 @@ if CONFIG['GNU_CXX']:
     if CONFIG['CPU_ARCH'] == 'arm':
         SOURCES['trunk/src/opts/SkBlitRow_opts_arm.cpp'].flags += ['-fomit-frame-pointer']
 
+if CONFIG['MOZ_NATIVE_HARFBUZZ']:
+    CXXFLAGS += CONFIG['MOZ_HARFBUZZ_CFLAGS']
+
+if CONFIG['MOZ_NATIVE_HARFBUZZ']:
+    CXXFLAGS += CONFIG['MOZ_HARFBUZZ_CFLAGS']
+
 if CONFIG['MOZ_WIDGET_TOOLKIT'] in ('gtk2', 'gtk3', 'android', 'gonk', 'qt'):
     CXXFLAGS += CONFIG['MOZ_CAIRO_CFLAGS']
     CXXFLAGS += CONFIG['CAIRO_FT_CFLAGS']
