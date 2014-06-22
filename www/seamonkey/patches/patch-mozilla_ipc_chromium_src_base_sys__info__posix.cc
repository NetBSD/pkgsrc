$NetBSD: patch-mozilla_ipc_chromium_src_base_sys__info__posix.cc,v 1.2 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/ipc/chromium/src/base/sys_info_posix.cc.orig	2014-06-13 00:45:30.000000000 +0000
+++ mozilla/ipc/chromium/src/base/sys_info_posix.cc
@@ -119,7 +119,11 @@ std::wstring SysInfo::GetEnvVar(const wc
 
 // static
 std::string SysInfo::OperatingSystemName() {
+#ifdef OS_SOLARIS
+  struct utsname info;
+#else
   utsname info;
+#endif
   if (uname(&info) < 0) {
     NOTREACHED();
     return "";
@@ -129,7 +133,11 @@ std::string SysInfo::OperatingSystemName
 
 // static
 std::string SysInfo::OperatingSystemVersion() {
+#ifdef OS_SOLARIS
+  struct utsname info;
+#else
   utsname info;
+#endif
   if (uname(&info) < 0) {
     NOTREACHED();
     return "";
