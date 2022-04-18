$NetBSD: patch-src_3rdparty_chromium_base_process_process__linux.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/process/process_linux.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/process/process_linux.cc
@@ -93,6 +93,9 @@ Time Process::CreationTime() const {
                                   Pid(), internal::VM_STARTTIME);
 #endif
 
+#if defined(OS_BSD)
+  return Time::FromTimeT(start_ticks);
+#else
   if (!start_ticks)
     return Time();
 
@@ -101,8 +104,11 @@ Time Process::CreationTime() const {
   if (boot_time.is_null())
     return Time();
   return Time(boot_time + start_offset);
+#endif
 }
 
+#if !defined(OS_BSD)
+  return Time::FromTimeT(start_ticks);
 // static
 bool Process::CanBackgroundProcesses() {
 #if defined(OS_CHROMEOS) || BUILDFLAG(IS_LACROS)
@@ -154,6 +160,7 @@ bool Process::SetProcessBackgrounded(boo
   DPCHECK(result == 0);
   return result == 0;
 }
+#endif
 
 #if defined(OS_CHROMEOS) || BUILDFLAG(IS_LACROS)
 bool IsProcessBackgroundedCGroup(const StringPiece& cgroup_contents) {
