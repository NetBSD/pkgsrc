$NetBSD: patch-src_3rdparty_chromium_services_network_network__service.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/services/network/network_service.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/services/network/network_service.h
@@ -196,7 +196,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) 
       base::span<const uint8_t> config,
       mojom::NetworkService::UpdateLegacyTLSConfigCallback callback) override;
   void OnCertDBChanged() override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   void SetCryptConfig(mojom::CryptConfigPtr crypt_config) override;
 #endif
 #if defined(OS_WIN) || defined(OS_MAC)
