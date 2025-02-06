$NetBSD: patch-chrome_browser_supervised__user_supervised__user__extensions__delegate__impl.cc,v 1.1 2025/02/06 09:57:51 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_extensions_delegate_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/supervised_user/supervised_user_extensions_delegate_impl.cc
@@ -194,7 +194,7 @@ void SupervisedUserExtensionsDelegateImp
       return;
     }
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   CHECK(contents.value());
   content::WebContents* web_contents = contents.value().get();
   if (CanInstallExtensions()) {
