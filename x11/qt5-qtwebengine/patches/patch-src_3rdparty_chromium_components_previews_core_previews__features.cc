$NetBSD: patch-src_3rdparty_chromium_components_previews_core_previews__features.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/previews/core/previews_features.cc.orig	2020-07-08 21:40:40.000000000 +0000
+++ src/3rdparty/chromium/components/previews/core/previews_features.cc
@@ -14,7 +14,7 @@ namespace features {
 // are enabled are controlled by other features.
 const base::Feature kPreviews {
   "Previews",
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
       // Previews allowed for Android (but also allow on Linux for dev/debug).
       base::FEATURE_ENABLED_BY_DEFAULT
 #else   // !defined(OS_ANDROID) || defined(OS_LINUX)
