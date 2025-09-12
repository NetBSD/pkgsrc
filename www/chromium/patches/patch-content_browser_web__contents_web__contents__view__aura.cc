$NetBSD: patch-content_browser_web__contents_web__contents__view__aura.cc,v 1.7 2025/09/12 16:02:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/web_contents/web_contents_view_aura.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ content/browser/web_contents/web_contents_view_aura.cc
@@ -175,7 +175,7 @@ class WebDragSourceAura : public content
   raw_ptr<aura::Window> window_;
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Fill out the OSExchangeData with a file contents, synthesizing a name if
 // necessary.
 void PrepareDragForFileContents(const DropData& drop_data,
@@ -260,7 +260,7 @@ void PrepareDragData(const DropData& dro
   if (!drop_data.download_metadata.empty())
     PrepareDragForDownload(drop_data, provider, web_contents);
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // We set the file contents before the URL because the URL also sets file
   // contents (to a .URL shortcut).  We want to prefer file content data over
   // a shortcut so we add it first.
@@ -1326,7 +1326,7 @@ void WebContentsViewAura::OnMouseEvent(u
     // Linux window managers like to handle raise-on-click themselves.  If we
     // raise-on-click manually, this may override user settings that prevent
     // focus-stealing.
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
     // It is possible for the web-contents to be destroyed while it is being
     // activated. Use a weak-ptr to track whether that happened or not.
     // More in https://crbug.com/1040725
