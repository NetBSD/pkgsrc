$NetBSD: patch-build_gn__processor.py,v 1.1 2025/10/27 14:24:33 ryoon Exp $

--- build/gn_processor.py.orig	2025-10-03 13:17:56.000000000 +0000
+++ build/gn_processor.py
@@ -190,6 +190,8 @@ def filter_gn_config(path, gn_result, sa
         "mac": "Darwin",
         "openbsd": "OpenBSD",
         "win": "WINNT",
+        "freebsd": "FreeBSD",
+        "netbsd": "NetBSD",
     }
 
     mozbuild_args = {
@@ -810,17 +812,17 @@ def main():
 
     vars_set = []
     for is_debug in (True, False):
-        for target_os in ("android", "linux", "mac", "openbsd", "win"):
+        for target_os in ("android", "linux", "mac", "openbsd", "win", "freebsd", "netbsd"):
             target_cpus = ["x64"]
-            if target_os in ("android", "linux", "mac", "win", "openbsd"):
+            if target_os in ("android", "linux", "mac", "win", "openbsd", "freebsd", "netbsd"):
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
@@ -834,7 +836,7 @@ def main():
                         vars["ozone_platform_x11"] = enable_x11
                         vars_set.append(vars.copy())
                 else:
-                    if target_os == "openbsd":
+                    if target_os in ("openbsd", "freebsd", "netbsd"):
                         vars["ozone_platform_x11"] = True
                     vars_set.append(vars)
 
