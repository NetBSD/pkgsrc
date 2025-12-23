$NetBSD: patch-ui_base_cursor_cursor__factory.h,v 1.13 2025/12/23 13:22:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/cursor/cursor_factory.h.orig	2025-12-17 23:05:18.000000000 +0000
+++ ui/base/cursor/cursor_factory.h
@@ -93,7 +93,7 @@ class COMPONENT_EXPORT(UI_BASE_CURSOR) C
   base::ObserverList<CursorFactoryObserver>::Unchecked observers_;
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_CURSOR)
 std::vector<std::string> CursorNamesFromType(mojom::CursorType type);
 #endif
