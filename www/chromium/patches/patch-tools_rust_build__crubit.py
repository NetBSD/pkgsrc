$NetBSD: patch-tools_rust_build__crubit.py,v 1.2 2026/11/19 19:46:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/rust/build_crubit.py.orig	2026-11-11 21:01:38.000000000 +0000
+++ tools/rust/build_crubit.py
@@ -127,7 +127,7 @@ CMAKE_STAMP_FILENAME = 'build_crubit_sta
 
 IS_WIN = sys.platform == 'win32'
 IS_MAC = sys.platform == 'darwin'
-IS_LINUX = sys.platform.startswith('linux')
+IS_LINUX = sys.platform.startswith(("linux","openbsd","freebsd","netbsd")):
 
 
 def GetCrubitCxxFlags():
