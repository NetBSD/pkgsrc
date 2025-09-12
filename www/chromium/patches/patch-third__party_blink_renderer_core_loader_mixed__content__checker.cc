$NetBSD: patch-third__party_blink_renderer_core_loader_mixed__content__checker.cc,v 1.6 2025/09/12 16:02:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/loader/mixed_content_checker.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ third_party/blink/renderer/core/loader/mixed_content_checker.cc
@@ -510,7 +510,7 @@ bool MixedContentChecker::ShouldBlockFet
   switch (context_type) {
     case mojom::blink::MixedContentContextType::kOptionallyBlockable:
 
-#if (BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)) && \
+#if (BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENABLE_CAST_RECEIVER)
       // Fuchsia WebEngine can be configured to allow loading Mixed Content from
       // an insecure IP address. This is a workaround to revert Fuchsia Cast
