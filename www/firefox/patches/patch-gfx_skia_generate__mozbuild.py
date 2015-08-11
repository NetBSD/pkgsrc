$NetBSD: patch-gfx_skia_generate__mozbuild.py,v 1.2 2015/08/11 23:48:18 ryoon Exp $

--- gfx/skia/generate_mozbuild.py.orig	2015-08-07 15:54:04.000000000 +0000
+++ gfx/skia/generate_mozbuild.py
@@ -142,6 +142,12 @@ if CONFIG['GNU_CXX']:
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
