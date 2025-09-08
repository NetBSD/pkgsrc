$NetBSD: patch-ui_base_cursor_cursor__factory.h,v 1.6 2025/09/08 13:24:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/cursor/cursor_factory.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ ui/base/cursor/cursor_factory.h
@@ -93,7 +93,7 @@ class COMPONENT_EXPORT(UI_BASE_CURSOR) C
   base::ObserverList<CursorFactoryObserver>::Unchecked observers_;
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_CURSOR)
 std::vector<std::string> CursorNamesFromType(mojom::CursorType type);
 #endif
