$NetBSD: patch-third__party_dawn_src_dawn_common_DRMUtils.cpp,v 1.5 2026/10/23 15:05:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/dawn/src/dawn/common/DRMUtils.cpp.orig	2026-10-19 20:07:21.000000000 +0000
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
