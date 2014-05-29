$NetBSD: patch-browser_components_build_nsModule.cpp,v 1.1 2014/05/29 17:03:58 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- browser/components/build/nsModule.cpp.orig	2014-05-06 22:55:10.000000000 +0000
+++ browser/components/build/nsModule.cpp
@@ -10,7 +10,7 @@
 
 #if defined(XP_WIN)
 #include "nsWindowsShellService.h"
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 #include "nsMacShellService.h"
 #elif defined(MOZ_WIDGET_GTK)
 #include "nsGNOMEShellService.h"
@@ -34,7 +34,7 @@ using namespace mozilla::browser;
 NS_GENERIC_FACTORY_CONSTRUCTOR(DirectoryProvider)
 #if defined(XP_WIN)
 NS_GENERIC_FACTORY_CONSTRUCTOR(nsWindowsShellService)
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacShellService)
 #elif defined(MOZ_WIDGET_GTK)
 NS_GENERIC_FACTORY_CONSTRUCTOR_INIT(nsGNOMEShellService, Init)
@@ -56,7 +56,7 @@ NS_DEFINE_NAMED_CID(NS_FEEDSNIFFER_CID);
 NS_DEFINE_NAMED_CID(NS_BROWSER_ABOUT_REDIRECTOR_CID);
 #if defined(XP_WIN)
 NS_DEFINE_NAMED_CID(NS_WINIEHISTORYENUMERATOR_CID);
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 NS_DEFINE_NAMED_CID(NS_SHELLSERVICE_CID);
 #endif
 
@@ -71,7 +71,7 @@ static const mozilla::Module::CIDEntry k
     { &kNS_BROWSER_ABOUT_REDIRECTOR_CID, false, nullptr, AboutRedirector::Create },
 #if defined(XP_WIN)
     { &kNS_WINIEHISTORYENUMERATOR_CID, false, nullptr, nsIEHistoryEnumeratorConstructor },
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
     { &kNS_SHELLSERVICE_CID, false, nullptr, nsMacShellServiceConstructor },
 #endif
     { nullptr }
@@ -114,7 +114,7 @@ static const mozilla::Module::ContractID
     { NS_ABOUT_MODULE_CONTRACTID_PREFIX "customizing", &kNS_BROWSER_ABOUT_REDIRECTOR_CID },
 #if defined(XP_WIN)
     { NS_IEHISTORYENUMERATOR_CONTRACTID, &kNS_WINIEHISTORYENUMERATOR_CID },
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
     { NS_SHELLSERVICE_CONTRACTID, &kNS_SHELLSERVICE_CID },
 #endif
     { nullptr }
