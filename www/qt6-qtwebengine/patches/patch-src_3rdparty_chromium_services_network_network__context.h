$NetBSD: patch-src_3rdparty_chromium_services_network_network__context.h,v 1.1 2025/12/21 09:38:37 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/network/network_context.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/services/network/network_context.h
@@ -696,7 +696,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) 
    public:
     explicit NetworkContextHttpAuthPreferences(NetworkService* network_service);
     ~NetworkContextHttpAuthPreferences() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool AllowGssapiLibraryLoad() const override;
 #endif  // BUILDFLAG(IS_LINUX)
    private:
