$NetBSD: patch-mozilla_toolkit_system_gnome_nsGnomeModule.cpp,v 1.1 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/toolkit/system/gnome/nsGnomeModule.cpp.orig	2014-12-03 06:23:26.000000000 +0000
+++ mozilla/toolkit/system/gnome/nsGnomeModule.cpp
@@ -22,6 +22,8 @@ NS_GENERIC_FACTORY_CONSTRUCTOR_INIT(nsGn
 NS_GENERIC_FACTORY_CONSTRUCTOR(nsGIOService)
 NS_GENERIC_FACTORY_CONSTRUCTOR_INIT(nsGSettingsService, Init)
 #endif
+#include "nsSystemAlertsService.h"
+NS_GENERIC_FACTORY_CONSTRUCTOR_INIT(nsSystemAlertsService, Init)
 
 #ifdef MOZ_ENABLE_GCONF
 NS_DEFINE_NAMED_CID(NS_GCONFSERVICE_CID);
@@ -33,6 +35,7 @@ NS_DEFINE_NAMED_CID(NS_GNOMEVFSSERVICE_C
 NS_DEFINE_NAMED_CID(NS_GIOSERVICE_CID);
 NS_DEFINE_NAMED_CID(NS_GSETTINGSSERVICE_CID);
 #endif
+NS_DEFINE_NAMED_CID(NS_SYSTEMALERTSSERVICE_CID);
 
 static const mozilla::Module::CIDEntry kGnomeCIDs[] = {
 #ifdef MOZ_ENABLE_GCONF
@@ -45,6 +48,7 @@ static const mozilla::Module::CIDEntry k
   { &kNS_GIOSERVICE_CID, false, nullptr, nsGIOServiceConstructor },
   { &kNS_GSETTINGSSERVICE_CID, false, nullptr, nsGSettingsServiceConstructor },
 #endif
+  { &kNS_SYSTEMALERTSSERVICE_CID, false, nullptr, nsSystemAlertsServiceConstructor },
   { nullptr }
 };
 
@@ -59,6 +63,7 @@ static const mozilla::Module::ContractID
   { NS_GIOSERVICE_CONTRACTID, &kNS_GIOSERVICE_CID },
   { NS_GSETTINGSSERVICE_CONTRACTID, &kNS_GSETTINGSSERVICE_CID },
 #endif
+  { NS_SYSTEMALERTSERVICE_CONTRACTID, &kNS_SYSTEMALERTSSERVICE_CID },
   { nullptr }
 };
 
