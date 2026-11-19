$NetBSD: patch-net_http_http__auth__preferences.cc,v 1.33 2026/11/19 19:46:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/http/http_auth_preferences.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ net/http/http_auth_preferences.cc
@@ -40,7 +40,7 @@ std::string HttpAuthPreferences::AuthAnd
 }
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool HttpAuthPreferences::AllowGssapiLibraryLoad() const {
   return allow_gssapi_library_load_;
 }
