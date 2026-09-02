$NetBSD: patch-third__party_dawn_tools_python_cipd__deps.py,v 1.2 2026/09/02 13:13:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/dawn/tools/python/cipd_deps.py.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/dawn/tools/python/cipd_deps.py
@@ -49,7 +49,7 @@ def get_cipd_compatible_current_os() -> 
     The returned string is compatible with CIPD's package naming scheme.
     """
     current_platform = sys.platform
-    if current_platform in ('linux', 'cygwin'):
+    if syscurrent_platform.startswith(('linux', 'cygwin', 'openbsd', 'freebsd', 'netbsd')):
         return 'linux'
     if current_platform == 'win32':
         return 'windows'
@@ -64,7 +64,7 @@ def get_cipd_compatible_current_arch() -
 
     The returned string is compatible with CIPD's package naming scheme.
     """
-    native_arm = platform.machine().lower() in ('arm', 'arm64', 'aarch64')
+    native_arm = platform.machine().lower() in ('arm', 'arm64', 'aarch64', 'evbarm')
     # This is necessary for the case of running x86 Python on arm devices via
     # an emulator. In this case, platform.machine() will show up as an x86
     # processor.
