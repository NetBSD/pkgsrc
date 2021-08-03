$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_bind__gen_style__format.py,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/style_format.py.orig	2020-07-15 18:56:02.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/style_format.py
@@ -29,6 +29,15 @@ def init(root_src_dir):
     elif sys.platform.startswith(("cygwin", "win")):
         platform = "win"
         exe_suffix = ".exe"
+    elif sys.platform.startswith("freebsd"):
+        platform = "freebsd"
+        exe_suffix = ""
+    elif sys.platform.startswith("openbsd"):
+        platform = "openbsd"
+        exe_suffix = ""
+    elif sys.platform.startswith("netbsd"):
+        platform = "netbsd"
+        exe_suffix = ""
     else:
         assert False, "Unknown platform: {}".format(sys.platform)
     buildtools_platform_dir = os.path.join(root_src_dir, "buildtools",
@@ -37,6 +46,7 @@ def init(root_src_dir):
     # //buildtools/<platform>/clang-format
     _clang_format_command_path = os.path.join(
         buildtools_platform_dir, "clang-format{}".format(exe_suffix))
+    _clang_format_command_path = "@PREFIX@/bin/clang-format"
 
     # //buildtools/<platform>/gn
     _gn_command_path = os.path.join(buildtools_platform_dir,
