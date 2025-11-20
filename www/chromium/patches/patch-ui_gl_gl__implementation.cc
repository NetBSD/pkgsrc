$NetBSD: patch-ui_gl_gl__implementation.cc,v 1.10 2025/11/20 08:36:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gl/gl_implementation.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ ui/gl/gl_implementation.cc
@@ -304,7 +304,7 @@ GetRequestedGLImplementationFromCommandL
     const base::CommandLine* command_line) {
   bool overrideUseSoftwareGL =
       command_line->HasSwitch(switches::kOverrideUseSoftwareGLForTests);
-#if BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_CHROMEOS_DEVICE))
   if (std::getenv("RUNNING_UNDER_RR")) {
     // https://rr-project.org/ is a Linux-only record-and-replay debugger that
