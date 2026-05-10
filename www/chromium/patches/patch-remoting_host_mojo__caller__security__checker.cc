$NetBSD: patch-remoting_host_mojo__caller__security__checker.cc,v 1.19 2026/05/10 15:30:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/mojo_caller_security_checker.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ remoting/host/mojo_caller_security_checker.cc
@@ -32,7 +32,7 @@
 namespace remoting {
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr auto kAllowedCallerProgramNames =
     base::MakeFixedFlatSet<base::FilePath::StringViewType>({
         "remote-open-url",
@@ -62,7 +62,7 @@ bool IsTrustedMojoEndpoint(
     const named_mojo_ipc_server::ConnectionInfo& caller) {
 #if BUILDFLAG(IS_MAC)
   return IsProcessTrusted(caller.audit_token, kAllowedIdentifiers);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
   static base::NoDestructor<base::FilePath> current_process_image_path(
       GetProcessImagePath(base::GetCurrentProcId()));
@@ -99,7 +99,7 @@ bool IsTrustedMojoEndpoint(
   base::FilePath::StringType program_name =
       caller_process_image_path.BaseName().value();
   if (!kAllowedCallerProgramNames.contains(program_name)) {
-#if BUILDFLAG(IS_LINUX) && !defined(NDEBUG)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(NDEBUG)
     // Linux binaries generated in out/Debug are underscore-separated. To make
     // debugging easier, we just check the name again with underscores replaced
     // with hyphens.
