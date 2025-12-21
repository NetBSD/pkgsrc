$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_bind__gen_style__format.py,v 1.1 2025/12/21 09:38:39 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/style_format.py.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/style_format.py
@@ -30,7 +30,7 @@ def init(root_src_dir, enable_style_form
 
     # Determine //buildtools/<platform>/ directory
     new_path_platform_suffix = ""
-    if sys.platform.startswith("linux"):
+    if sys.platform.startswith(("linux","openbsd","freebsd","netbsd")):
         platform = "linux64"
         exe_suffix = ""
     elif sys.platform.startswith("darwin"):
