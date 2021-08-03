$NetBSD: patch-src_3rdparty_chromium_base_process_process__linux.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/process/process_linux.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/process/process_linux.cc
@@ -80,6 +80,9 @@ Time Process::CreationTime() const {
                                   internal::VM_STARTTIME)
                             : internal::ReadProcStatsAndGetFieldAsInt64(
                                   Pid(), internal::VM_STARTTIME);
+#if defined(OS_BSD)
+  return Time::FromTimeT(start_ticks);
+#else
   if (!start_ticks)
     return Time();
   TimeDelta start_offset = internal::ClockTicksToTimeDelta(start_ticks);
@@ -87,8 +90,11 @@ Time Process::CreationTime() const {
   if (boot_time.is_null())
     return Time();
   return Time(boot_time + start_offset);
+#endif
 }
 
+#if !defined(OS_BSD)
+  return Time::FromTimeT(start_ticks);
 // static
 bool Process::CanBackgroundProcesses() {
 #if defined(OS_CHROMEOS)
@@ -140,6 +146,7 @@ bool Process::SetProcessBackgrounded(boo
   DPCHECK(result == 0);
   return result == 0;
 }
+#endif
 
 #if defined(OS_CHROMEOS)
 bool IsProcessBackgroundedCGroup(const StringPiece& cgroup_contents) {
