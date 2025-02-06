$NetBSD: patch-content_browser_browser__child__process__host__impl__receiver__bindings.cc,v 1.1 2025/02/06 09:58:04 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/browser_child_process_host_impl_receiver_bindings.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/browser_child_process_host_impl_receiver_bindings.cc
@@ -62,7 +62,7 @@ void BrowserChildProcessHostImpl::BindHo
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (auto r = receiver.As<mojom::ThreadTypeSwitcher>()) {
     child_thread_type_switcher_.Bind(std::move(r));
     return;
