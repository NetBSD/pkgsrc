$NetBSD: patch-src_3rdparty_chromium_ui_gl_gl__implementation.cc,v 1.1 2025/12/21 09:38:48 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/gl/gl_implementation.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/ui/gl/gl_implementation.cc
@@ -253,7 +253,7 @@ GetRequestedGLImplementationFromCommandL
     const base::CommandLine* command_line) {
   bool overrideUseSoftwareGL =
       command_line->HasSwitch(switches::kOverrideUseSoftwareGLForTests);
-#if BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_CHROMEOS_DEVICE))
   if (std::getenv("RUNNING_UNDER_RR")) {
     // https://rr-project.org/ is a Linux-only record-and-replay debugger that
