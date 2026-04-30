$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_loader_mixed__content__checker.cc,v 1.1 2026/04/30 06:39:43 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/core/loader/mixed_content_checker.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/loader/mixed_content_checker.cc
@@ -510,7 +510,7 @@ bool MixedContentChecker::ShouldBlockFet
   switch (context_type) {
     case mojom::blink::MixedContentContextType::kOptionallyBlockable:
 
-#if (BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)) && \
+#if (BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENABLE_CAST_RECEIVER)
       // Fuchsia WebEngine can be configured to allow loading Mixed Content from
       // an insecure IP address. This is a workaround to revert Fuchsia Cast
