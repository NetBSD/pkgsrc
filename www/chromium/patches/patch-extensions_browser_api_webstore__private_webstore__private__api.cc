$NetBSD: patch-extensions_browser_api_webstore__private_webstore__private__api.cc,v 1.3 2026/09/29 07:42:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/browser/api/webstore_private/webstore_private_api.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ extensions/browser/api/webstore_private/webstore_private_api.cc
@@ -1190,7 +1190,7 @@ void WebstorePrivateBeginInstallWithMani
 #if BUILDFLAG(IS_CHROMEOS)
       RequestExtensionApproval(contents);
       return;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       // Shows a parental permission dialog directly bypassing the extension
       // install dialog view. The parental permission dialog contains a superset
       // of data from the extension install dialog: requested extension
