$NetBSD: patch-chrome_browser_extensions_api_webstore__private_webstore__private__api.cc,v 1.11 2025/12/11 09:13:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/webstore_private/webstore_private_api.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/browser/extensions/api/webstore_private/webstore_private_api.cc
@@ -937,7 +937,7 @@ void WebstorePrivateBeginInstallWithMani
 #if BUILDFLAG(IS_CHROMEOS)
       RequestExtensionApproval(contents);
       return;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       // Shows a parental permission dialog directly bypassing the extension
       // install dialog view. The parental permission dialog contains a superset
       // of data from the extension install dialog: requested extension
