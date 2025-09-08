$NetBSD: patch-content_shell_utility_shell__content__utility__client.cc,v 1.6 2025/09/08 13:24:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/shell/utility/shell_content_utility_client.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ content/shell/utility/shell_content_utility_client.cc
@@ -43,7 +43,7 @@
 #include "sandbox/policy/sandbox.h"
 #include "services/test/echo/echo_service.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/test/sandbox_status_service.h"
 #endif
 
@@ -192,7 +192,7 @@ void ShellContentUtilityClient::ExposeIn
   binders->Add<mojom::PowerMonitorTest>(
       &PowerMonitorTestImpl::MakeSelfOwnedReceiver,
       base::SingleThreadTaskRunner::GetCurrentDefault());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (register_sandbox_status_helper_) {
     binders->Add<content::mojom::SandboxStatusService>(
         base::BindRepeating(
