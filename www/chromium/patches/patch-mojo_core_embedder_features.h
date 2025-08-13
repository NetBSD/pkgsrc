$NetBSD: patch-mojo_core_embedder_features.h,v 1.5 2025/08/13 07:44:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/core/embedder/features.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ mojo/core/embedder/features.h
@@ -16,7 +16,7 @@ namespace core {
 
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_NACL) && \
     !BUILDFLAG(MOJO_USE_APPLE_CHANNEL)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(MOJO_CORE_EMBEDDER_FEATURES)
 BASE_DECLARE_FEATURE(kMojoLinuxChannelSharedMem);
 
