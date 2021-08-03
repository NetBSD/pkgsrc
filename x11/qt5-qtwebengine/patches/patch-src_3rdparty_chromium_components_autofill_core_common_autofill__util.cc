$NetBSD: patch-src_3rdparty_chromium_components_autofill_core_common_autofill__util.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/autofill/core/common/autofill_util.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ src/3rdparty/chromium/components/autofill/core/common/autofill_util.cc
@@ -213,7 +213,7 @@ bool SanitizedFieldIsEmpty(const base::s
 }
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return true;
 #else
   return false;
