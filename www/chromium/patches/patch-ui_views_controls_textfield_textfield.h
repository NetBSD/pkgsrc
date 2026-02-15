$NetBSD: patch-ui_views_controls_textfield_textfield.h,v 1.15 2026/02/15 09:04:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/controls/textfield/textfield.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ ui/views/controls/textfield/textfield.h
@@ -49,7 +49,7 @@
 #include "ui/views/view_observer.h"
 #include "ui/views/word_lookup_client.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <vector>
 #endif
 
@@ -479,7 +479,7 @@ class VIEWS_EXPORT Textfield : public Vi
   // Set whether the text should be used to improve typing suggestions.
   void SetShouldDoLearning(bool value) { should_do_learning_ = value; }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
