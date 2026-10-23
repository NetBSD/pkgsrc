$NetBSD: patch-base_allocator_partition__alloc__features.cc,v 1.13 2026/10/23 15:05:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_alloc_features.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ base/allocator/partition_alloc_features.cc
@@ -132,7 +132,7 @@ constinit const FeatureParam<std::string
     kPartitionAllocSchedulerLoopQuarantineConfig{
         &kPartitionAllocSchedulerLoopQuarantine,
         "PartitionAllocSchedulerLoopQuarantineConfig",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
         R"({
           "browser":{
             "main":{
