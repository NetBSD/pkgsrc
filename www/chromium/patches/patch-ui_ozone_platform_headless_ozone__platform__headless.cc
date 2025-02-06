$NetBSD: patch-ui_ozone_platform_headless_ozone__platform__headless.cc,v 1.1 2025/02/06 09:58:33 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/headless/ozone_platform_headless.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/ozone/platform/headless/ozone_platform_headless.cc
@@ -103,7 +103,7 @@ class OzonePlatformHeadless : public Ozo
   }
 
 // Desktop Linux, not CastOS.
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
   const PlatformProperties& GetPlatformProperties() override {
     static base::NoDestructor<OzonePlatform::PlatformProperties> properties;
     static bool initialized = false;
