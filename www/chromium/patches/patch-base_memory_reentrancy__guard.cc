$NetBSD: patch-base_memory_reentrancy__guard.cc,v 1.1 2026/11/19 19:45:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/memory/reentrancy_guard.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ base/memory/reentrancy_guard.cc
@@ -9,7 +9,7 @@
 
 namespace base::internal {
 
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
 std::atomic<int> ReentrancyState::Guard::guard_count_{0};
 std::array<std::atomic<ReentrancyState::PlatformThreadRef>,
            ReentrancyState::Guard::kCapacity>
