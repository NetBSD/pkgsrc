$NetBSD: patch-ui_base_ime_fake__text__input__client.h,v 1.14 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ime/fake_text_input_client.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/base/ime/fake_text_input_client.h
@@ -107,7 +107,7 @@ class FakeTextInputClient : public TextI
   void SetTextEditCommandForNextKeyEvent(TextEditCommand command) override;
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
