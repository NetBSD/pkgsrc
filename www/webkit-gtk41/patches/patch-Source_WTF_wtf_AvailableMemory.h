$NetBSD: patch-Source_WTF_wtf_AvailableMemory.h,v 1.1 2026/09/22 12:27:03 wiz Exp $

Add NetBSD support for memoryStatus.

--- Source/WTF/wtf/AvailableMemory.h.orig	2026-09-16 20:05:45.962495471 +0000
+++ Source/WTF/wtf/AvailableMemory.h
@@ -32,7 +32,7 @@ WTF_EXPORT_PRIVATE size_t availableMemory();
 
 WTF_EXPORT_PRIVATE size_t availableMemory();
 
-#if PLATFORM(IOS_FAMILY) || OS(LINUX) || OS(FREEBSD)
+#if PLATFORM(IOS_FAMILY) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD)
 struct MemoryStatus {
     MemoryStatus(size_t memoryFootprint, double percentAvailableMemoryInUse)
         : memoryFootprint(memoryFootprint)
@@ -55,7 +55,7 @@ inline bool isUnderMemoryPressure()
 
 inline bool isUnderMemoryPressure()
 {
-#if PLATFORM(IOS_FAMILY) || OS(LINUX) || OS(FREEBSD)
+#if PLATFORM(IOS_FAMILY) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD)
     constexpr double memoryPressureThreshold = 0.75;
     return percentAvailableMemoryInUse() > memoryPressureThreshold;
 #else
