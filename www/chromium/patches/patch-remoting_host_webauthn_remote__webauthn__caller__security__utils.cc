$NetBSD: patch-remoting_host_webauthn_remote__webauthn__caller__security__utils.cc,v 1.1 2025/02/06 09:58:18 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/webauthn/remote_webauthn_caller_security_utils.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ remoting/host/webauthn/remote_webauthn_caller_security_utils.cc
@@ -10,7 +10,7 @@
 #include "base/strings/utf_string_conversions.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "base/containers/fixed_flat_set.h"
 #include "base/files/file_path.h"
 #include "base/process/process_handle.h"
@@ -38,7 +38,7 @@ namespace {
 
 // No static variables needed for debug builds.
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 constexpr auto kAllowedCallerPrograms =
     base::MakeFixedFlatSet<base::FilePath::StringPieceType>({
@@ -82,7 +82,7 @@ bool IsLaunchedByTrustedProcess() {
 #if !defined(NDEBUG)
   // Just return true on debug builds for the convenience of development.
   return true;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ProcessId parent_pid =
       base::GetParentProcessId(base::GetCurrentProcessHandle());
   // Note that on Linux the process image may no longer exist in its original
