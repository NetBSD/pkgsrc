$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_bind__gen_style__format.py,v 1.2 2023/06/08 20:38:06 markd Exp $

support freebsd openbsd netbsd
build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/style_format.py.orig	2022-03-30 09:48:18.000000000 +0000
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
@@ -70,8 +80,13 @@ def gn_format(contents, filename=None):
 
 
 def _invoke_format_command(command_line, filename, contents):
-    proc = subprocess.Popen(
-        command_line, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
+    kwargs = {}
+    if sys.version_info.major != 2:
+        kwargs['encoding'] = 'utf-8'
+    proc = subprocess.Popen(command_line,
+                            stdin=subprocess.PIPE,
+                            stdout=subprocess.PIPE,
+                            **kwargs)
     stdout_output, stderr_output = proc.communicate(input=contents)
     exit_code = proc.wait()
 
