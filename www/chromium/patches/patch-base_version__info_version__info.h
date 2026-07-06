$NetBSD: patch-base_version__info_version__info.h,v 1.22 2026/07/06 13:06:42 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/version_info/version_info.h.orig	2026-06-23 23:37:18.000000000 +0000
+++ base/version_info/version_info.h
@@ -74,6 +74,8 @@ constexpr std::string_view GetOSType() {
   return "FreeBSD";
 #elif BUILDFLAG(IS_OPENBSD)
   return "OpenBSD";
+#elif BUILDFLAG(IS_NETBSD)
+  return "NetBSD";
 #elif BUILDFLAG(IS_SOLARIS)
   return "Solaris";
 #elif BUILDFLAG(IS_FUCHSIA)
