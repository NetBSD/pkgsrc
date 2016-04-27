$NetBSD: patch-gfx_skia_generate__mozbuild.py,v 1.4 2016/04/27 16:22:40 ryoon Exp $

--- gfx/skia/generate_mozbuild.py.orig	2016-04-15 16:57:40.000000000 +0000
+++ gfx/skia/generate_mozbuild.py
@@ -135,6 +135,12 @@ if CONFIG['CLANG_CXX'] or CONFIG['CLANG_
         '-Wno-unused-private-field',
     ]
 
+if CONFIG['MOZ_NATIVE_HARFBUZZ']:
+    CXXFLAGS += CONFIG['MOZ_HARFBUZZ_CFLAGS']
+
+if CONFIG['MOZ_NATIVE_HARFBUZZ']:
+    CXXFLAGS += CONFIG['MOZ_HARFBUZZ_CFLAGS']
+
 if CONFIG['MOZ_WIDGET_TOOLKIT'] in ('gtk2', 'gtk3', 'android', 'gonk', 'qt'):
     CXXFLAGS += CONFIG['MOZ_CAIRO_CFLAGS']
     CXXFLAGS += CONFIG['CAIRO_FT_CFLAGS']
