$NetBSD: patch-chrome_browser_ui_views_hung__renderer__view.cc,v 1.11 2025/12/11 09:13:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/hung_renderer_view.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/browser/ui/views/hung_renderer_view.cc
@@ -452,7 +452,7 @@ void HungRendererDialogView::ForceCrashH
   content::RenderProcessHost* rph =
       hung_pages_table_model_->GetRenderWidgetHost()->GetProcess();
   if (rph) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // A generic |CrashDumpHungChildProcess()| is not implemented for Linux.
     // Instead we send an explicit IPC to crash on the renderer's IO thread.
     rph->ForceCrash();
