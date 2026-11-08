$NetBSD: patch-tools_rust_build__crubit.py,v 1.1 2026/11/08 15:39:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/rust/build_crubit.py.orig	2026-11-02 23:22:33.000000000 +0000
+++ tools/rust/build_crubit.py
@@ -128,7 +128,7 @@ CMAKE_STAMP_FILENAME = 'build_crubit_sta
 
 IS_WIN = sys.platform == 'win32'
 IS_MAC = sys.platform == 'darwin'
-IS_LINUX = sys.platform.startswith('linux')
+IS_LINUX = sys.platform.startswith(("linux","openbsd","freebsd","netbsd")):
 
 
 def GetCrubitCxxFlags():
