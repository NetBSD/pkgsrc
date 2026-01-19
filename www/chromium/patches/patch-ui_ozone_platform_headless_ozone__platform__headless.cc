$NetBSD: patch-ui_ozone_platform_headless_ozone__platform__headless.cc,v 1.14 2026/01/19 16:14:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/headless/ozone_platform_headless.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/ozone/platform/headless/ozone_platform_headless.cc
@@ -108,7 +108,7 @@ class OzonePlatformHeadlessImpl : public
   }
 
 // Desktop Linux, not CastOS.
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
   const PlatformProperties& GetPlatformProperties() override {
     static base::NoDestructor<OzonePlatform::PlatformProperties> properties;
     static bool initialized = false;
