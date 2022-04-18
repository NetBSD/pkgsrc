$NetBSD: patch-src_3rdparty_chromium_base_memory_discardable__memory.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/memory/discardable_memory.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/memory/discardable_memory.cc
@@ -23,7 +23,7 @@ const base::Feature kMadvFreeDiscardable
     "MadvFreeDiscardableMemory", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const base::Feature kDiscardableMemoryBackingTrial{
     "DiscardableMemoryBackingTrial", base::FEATURE_DISABLED_BY_DEFAULT};
 
@@ -47,7 +47,7 @@ const base::FeatureParam<DiscardableMemo
 
 namespace {
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 DiscardableMemoryBacking GetBackingForFieldTrial() {
   DiscardableMemoryTrialGroup trial_group =
@@ -65,7 +65,7 @@ DiscardableMemoryBacking GetBackingForFi
 
 }  // namespace
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // Probe capabilities of this device to determine whether we should participate
 // in the discardable memory backing trial.
@@ -94,7 +94,7 @@ DiscardableMemory::DiscardableMemory() =
 DiscardableMemory::~DiscardableMemory() = default;
 
 DiscardableMemoryBacking GetDiscardableMemoryBacking() {
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (DiscardableMemoryBackingFieldTrialIsEnabled()) {
     return GetBackingForFieldTrial();
   }
