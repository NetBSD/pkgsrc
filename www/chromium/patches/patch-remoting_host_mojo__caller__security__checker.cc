$NetBSD: patch-remoting_host_mojo__caller__security__checker.cc,v 1.1 2025/02/06 09:58:18 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/mojo_caller_security_checker.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ remoting/host/mojo_caller_security_checker.cc
@@ -37,7 +37,7 @@
 namespace remoting {
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr auto kAllowedCallerProgramNames =
     base::MakeFixedFlatSet<base::FilePath::StringPieceType>({
         "remote-open-url",
@@ -98,7 +98,7 @@ bool IsTrustedMojoEndpoint(
   return true;
 #endif
 
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
   // TODO: yuweih - see if it's possible to move away from PID-based security
   // checks, which might be susceptible of PID reuse attacks.
@@ -122,7 +122,7 @@ bool IsTrustedMojoEndpoint(
   base::FilePath::StringType program_name =
       caller_process_image_path.BaseName().value();
   if (!kAllowedCallerProgramNames.contains(program_name)) {
-#if BUILDFLAG(IS_LINUX) && !defined(NDEBUG)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(NDEBUG)
     // Linux binaries generated in out/Debug are underscore-separated. To make
     // debugging easier, we just check the name again with underscores replaced
     // with hyphens.
