$NetBSD: patch-src_3rdparty_chromium_ui_views_controls_textfield_textfield.h,v 1.1 2025/12/21 09:38:49 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/views/controls/textfield/textfield.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/ui/views/controls/textfield/textfield.h
@@ -47,7 +47,7 @@
 #include "ui/views/view_observer.h"
 #include "ui/views/word_lookup_client.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <vector>
 #endif
 
@@ -463,7 +463,7 @@ class VIEWS_EXPORT Textfield : public Vi
   // Set whether the text should be used to improve typing suggestions.
   void SetShouldDoLearning(bool value) { should_do_learning_ = value; }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
