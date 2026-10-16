$NetBSD: patch-chrome_browser_component__updater_private__verification__tokens__installer.cc,v 1.4 2026/10/16 15:30:44 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/component_updater/private_verification_tokens_installer.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/component_updater/private_verification_tokens_installer.cc
@@ -30,6 +30,10 @@ void RegisterPrivateVerificationTokensCo
     return;
   }
 
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return;
+#else
   auto installer = base::MakeRefCounted<ComponentInstaller>(
       std::make_unique<PrivateVerificationTokensInstallerPolicy>(
           base::BindRepeating(
@@ -51,6 +55,7 @@ void RegisterPrivateVerificationTokensCo
               })));
 
   installer->Register(cus, base::OnceClosure());
+#endif
 }
 
 }  // namespace component_updater
