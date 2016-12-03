$NetBSD: patch-gfx_skia_generate__mozbuild.py,v 1.6 2016/12/03 09:58:26 ryoon Exp $

--- gfx/skia/generate_mozbuild.py.orig	2016-10-31 20:15:31.000000000 +0000
+++ gfx/skia/generate_mozbuild.py
@@ -140,6 +140,9 @@ if CONFIG['CLANG_CXX'] or CONFIG['CLANG_
         '-Wno-unused-private-field',
     ]
 
+if CONFIG['MOZ_SYSTEM_HARFBUZZ']:
+    CXXFLAGS += CONFIG['MOZ_HARFBUZZ_CFLAGS']
+
 if CONFIG['MOZ_WIDGET_TOOLKIT'] in ('gtk2', 'gtk3', 'android', 'gonk'):
     CXXFLAGS += CONFIG['MOZ_CAIRO_CFLAGS']
     CXXFLAGS += CONFIG['CAIRO_FT_CFLAGS']
