$NetBSD: patch-src_3rdparty_chromium_ui_base_ime_dummy__text__input__client.h,v 1.1 2025/12/21 09:38:46 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/base/ime/dummy_text_input_client.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/ui/base/ime/dummy_text_input_client.h
@@ -67,7 +67,7 @@ class DummyTextInputClient : public Text
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
