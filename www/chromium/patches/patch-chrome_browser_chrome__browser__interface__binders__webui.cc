$NetBSD: patch-chrome_browser_chrome__browser__interface__binders__webui.cc,v 1.22 2026/07/08 13:42:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_interface_binders_webui.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ chrome/browser/chrome_browser_interface_binders_webui.cc
@@ -90,13 +90,13 @@
 #endif  // !BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_DESKTOP_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/discards/discards.mojom.h"
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
 #include "chrome/browser/ui/webui/discards/site_data.mojom.h"
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/skills/skills.mojom.h"
 #include "chrome/browser/ui/webui/skills/skills_ui.h"
 #endif
@@ -337,7 +337,7 @@ void PopulateChromeWebUIFrameBinders(
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<discards::mojom::DetailsProvider,
                                          DiscardsUI>(map);
 
@@ -349,7 +349,7 @@ void PopulateChromeWebUIFrameBinders(
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<skills::mojom::PageHandlerFactory,
                                          skills::SkillsUI>(map);
 #endif
