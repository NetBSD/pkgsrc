$NetBSD: patch-ipc_chromium_src_base_sys__info__posix.cc,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- ipc/chromium/src/base/sys_info_posix.cc.orig	2014-01-28 04:03:44.000000000 +0000
+++ ipc/chromium/src/base/sys_info_posix.cc
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
@@ -139,7 +147,11 @@ std::string SysInfo::OperatingSystemVers
 
 // static
 std::string SysInfo::CPUArchitecture() {
+#ifdef OS_SOLARIS
+  struct utsname info;
+#else
   utsname info;
+#endif
   if (uname(&info) < 0) {
     NOTREACHED();
     return "";
