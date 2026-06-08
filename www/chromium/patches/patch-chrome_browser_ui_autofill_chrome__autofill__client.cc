$NetBSD: patch-chrome_browser_ui_autofill_chrome__autofill__client.cc,v 1.1 2026/06/08 13:12:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/autofill/chrome_autofill_client.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ chrome/browser/ui/autofill/chrome_autofill_client.cc
@@ -315,7 +315,7 @@ ChromeAutofillClient::~ChromeAutofillCli
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 ChromeAutofillClient::AtMemoryPromoObserver::AtMemoryPromoObserver(
     ChromeAutofillClient* client)
     : content::WebContentsObserver(client->web_contents()), client_(*client) {}
