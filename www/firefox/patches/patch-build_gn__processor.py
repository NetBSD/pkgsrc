$NetBSD: patch-build_gn__processor.py,v 1.2 2026/09/23 08:39:50 ryoon Exp $

--- build/gn_processor.py.orig	2026-09-09 20:41:32.000000000 +0000
+++ build/gn_processor.py
@@ -220,6 +220,8 @@ def filter_gn_config(path, gn_result, sandbox_vars, in
         "ios": "Darwin",
         "openbsd": "OpenBSD",
         "win": "WINNT",
+        "freebsd": "FreeBSD",
+        "netbsd": "NetBSD",
     }
 
     mozbuild_args = {
@@ -1063,17 +1065,17 @@ def generate_gn_configs(topsrcdir, config):
 
     vars_set = []
     for is_debug in (True, False):
-        for target_os in ("android", "ios", "linux", "mac", "openbsd", "win"):
+        for target_os in ("android", "ios", "linux", "mac", "openbsd", "win", "freebsd", "netbsd"):
             target_cpus = ["x64"]
-            if target_os in ("android", "ios", "linux", "mac", "win", "openbsd"):
+            if target_os in ("android", "ios", "linux", "mac", "win", "openbsd", "freebsd", "netbsd"):
                 target_cpus.append("arm64")
-            if target_os in ("android", "linux"):
+            if target_os in ("android", "linux", "freebsd", "netbsd"):
                 target_cpus.append("arm")
-            if target_os in ("android", "linux", "win"):
+            if target_os in ("android", "linux", "win", "freebsd", "netbsd"):
                 target_cpus.append("x86")
-            if target_os in ("linux", "openbsd"):
+            if target_os in ("linux", "openbsd", "freebsd", "netbsd"):
                 target_cpus.append("riscv64")
-            if target_os == "linux":
+            if target_os in ("linux", "openbsd", "freebsd", "netbsd"):
                 target_cpus.extend(["loong64", "ppc64", "mipsel", "mips64el"])
             for target_cpu in target_cpus:
                 vars = {
@@ -1092,7 +1094,7 @@ def generate_gn_configs(topsrcdir, config):
                         vars["ozone_platform_x11"] = enable_x11
                         vars_set.append(vars.copy())
                 else:
-                    if target_os == "openbsd":
+                    if target_os in ("openbsd", "freebsd", "netbsd"):
                         vars["ozone_platform_x11"] = True
                     vars_set.append(vars)
 
