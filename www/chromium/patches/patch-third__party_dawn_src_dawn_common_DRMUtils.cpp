$NetBSD: patch-third__party_dawn_src_dawn_common_DRMUtils.cpp,v 1.7 2026/11/19 19:46:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/dawn/src/dawn/common/DRMUtils.cpp.orig	2026-11-11 21:01:38.000000000 +0000
+++ third_party/dawn/src/dawn/common/DRMUtils.cpp
@@ -30,7 +30,9 @@
 #include <dirent.h>
 #include <fcntl.h>
 #include <sys/stat.h>
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <sys/sysmacros.h>
+#endif
 
 #include <algorithm>
 #include <cctype>
