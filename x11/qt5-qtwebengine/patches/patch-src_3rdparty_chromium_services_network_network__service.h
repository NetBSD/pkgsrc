$NetBSD: patch-src_3rdparty_chromium_services_network_network__service.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/network/network_service.h.orig	2020-07-15 18:56:01.000000000 +0000
+++ src/3rdparty/chromium/services/network/network_service.h
@@ -192,7 +192,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) 
       base::span<const uint8_t> config,
       mojom::NetworkService::UpdateLegacyTLSConfigCallback callback) override;
   void OnCertDBChanged() override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   void SetCryptConfig(mojom::CryptConfigPtr crypt_config) override;
 #endif
 #if defined(OS_WIN) || (defined(OS_MACOSX) && !defined(OS_IOS))
