$NetBSD: patch-chrome_browser_enterprise_connectors_device__trust_key__management_core_persistence_key__persistence__delegate__factory.cc,v 1.16 2026/03/14 12:40:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/device_trust/key_management/core/persistence/key_persistence_delegate_factory.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/enterprise/connectors/device_trust/key_management/core/persistence/key_persistence_delegate_factory.cc
@@ -13,7 +13,7 @@
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/core/persistence/win_key_persistence_delegate.h"
 #elif BUILDFLAG(IS_MAC)
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/core/persistence/mac_key_persistence_delegate.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/core/persistence/linux_key_persistence_delegate.h"
 #endif
 
@@ -45,7 +45,7 @@ KeyPersistenceDelegateFactory::CreateKey
   return std::make_unique<WinKeyPersistenceDelegate>();
 #elif BUILDFLAG(IS_MAC)
   return std::make_unique<MacKeyPersistenceDelegate>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<LinuxKeyPersistenceDelegate>();
 #else
   NOTREACHED();
