$NetBSD: patch-mozilla_ipc_chromium_src_base_sys__info__posix.cc,v 1.3 2017/01/01 16:14:08 ryoon Exp $

--- mozilla/ipc/chromium/src/base/sys_info_posix.cc.orig	2016-12-14 02:07:49.000000000 +0000
+++ mozilla/ipc/chromium/src/base/sys_info_posix.cc
@@ -121,7 +121,11 @@ std::wstring SysInfo::GetEnvVar(const wc
 
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
