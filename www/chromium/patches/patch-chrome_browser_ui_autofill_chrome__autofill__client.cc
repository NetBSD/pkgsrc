$NetBSD: patch-chrome_browser_ui_autofill_chrome__autofill__client.cc,v 1.3 2026/07/08 13:42:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/autofill/chrome_autofill_client.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ chrome/browser/ui/autofill/chrome_autofill_client.cc
@@ -321,7 +321,7 @@ ChromeAutofillClient::~ChromeAutofillCli
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 ChromeAutofillClient::AtMemoryPromoObserver::AtMemoryPromoObserver(
     ChromeAutofillClient* client)
     : content::WebContentsObserver(client->web_contents()), client_(*client) {}
