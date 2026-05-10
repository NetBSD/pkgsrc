$NetBSD: patch-v8_src_base_sys-info.cc,v 1.19 2026/05/10 15:30:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/sys-info.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ v8/src/base/sys-info.cc
@@ -35,8 +35,12 @@ namespace base {
 
 // static
 int SysInfo::NumberOfProcessors() {
+#if V8_OS_OPENBSD || V8_OS_NETBSD
 #if V8_OS_OPENBSD
+  int mib[2] = {CTL_HW, HW_NCPUONLINE};
+#else
   int mib[2] = {CTL_HW, HW_NCPU};
+#endif
   int ncpu = 0;
   size_t len = sizeof(ncpu);
   if (sysctl(mib, arraysize(mib), &ncpu, &len, nullptr, 0) != 0) {
