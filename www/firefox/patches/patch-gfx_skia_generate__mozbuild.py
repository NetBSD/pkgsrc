$NetBSD: patch-gfx_skia_generate__mozbuild.py,v 1.7.10.1 2018/03/22 06:56:21 spz Exp $

--- gfx/skia/generate_mozbuild.py.orig	2018-03-10 02:54:17.000000000 +0000
+++ gfx/skia/generate_mozbuild.py
@@ -137,6 +137,9 @@ if CONFIG['CC_TYPE'] in ('clang', 'clang
         '-Wno-unused-private-field',
     ]
 
+if CONFIG['MOZ_SYSTEM_HARFBUZZ']:
+    CXXFLAGS += CONFIG['MOZ_HARFBUZZ_CFLAGS']
+
 if CONFIG['MOZ_WIDGET_TOOLKIT'] in ('gtk3', 'android'):
     CXXFLAGS += CONFIG['MOZ_CAIRO_CFLAGS']
     CXXFLAGS += CONFIG['CAIRO_FT_CFLAGS']
