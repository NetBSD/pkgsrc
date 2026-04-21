$NetBSD: patch-gpu_ipc_service_shared__image__stub.cc,v 1.3 2026/04/21 15:21:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/ipc/service/shared_image_stub.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ gpu/ipc/service/shared_image_stub.cc
@@ -48,7 +48,7 @@ SharedImageStub::SharedImageStub(GpuChan
       command_buffer_id_(
           CommandBufferIdFromChannelAndRoute(channel->client_id(), route_id)),
       sequence_(channel->scheduler()->CreateSequence(
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           base::FeatureList::IsEnabled(features::kSharedImageStubHighPriority)
               ? SchedulingPriority::kHigh
               : SchedulingPriority::kLow,
