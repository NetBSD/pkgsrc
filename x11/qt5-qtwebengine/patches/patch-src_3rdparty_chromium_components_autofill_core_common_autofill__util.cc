$NetBSD: patch-src_3rdparty_chromium_components_autofill_core_common_autofill__util.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/autofill/core/common/autofill_util.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/autofill/core/common/autofill_util.cc
@@ -175,7 +175,7 @@ bool SanitizedFieldIsEmpty(const base::s
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   return true;
 #else
   return false;
