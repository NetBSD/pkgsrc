$NetBSD: patch-ui_base_x_x11__cursor__loader.cc,v 1.1 2025/02/06 09:58:31 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/x/x11_cursor_loader.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/base/x/x11_cursor_loader.cc
@@ -34,7 +34,7 @@
 #include "ui/gfx/x/connection.h"
 #include "ui/gfx/x/xproto.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -59,7 +59,11 @@ std::string CursorPathFromLibXcursor() {
     void operator()(void* ptr) const { dlclose(ptr); }
   };
 
+#if BUILDFLAG(IS_BSD)
+  std::unique_ptr<void, DlCloser> lib(dlopen("libXcursor.so", RTLD_LAZY));
+#else
   std::unique_ptr<void, DlCloser> lib(dlopen("libXcursor.so.1", RTLD_LAZY));
+#endif
   if (!lib)
     return "";
 
@@ -170,7 +174,7 @@ scoped_refptr<base::RefCountedMemory> Re
     const std::string& rm_xcursor_theme) {
   constexpr const char kDefaultTheme[] = "default";
   std::string themes[] = {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // The toolkit theme has the highest priority.
     LinuxUi::instance() ? LinuxUi::instance()->GetCursorThemeName()
                         : std::string(),
@@ -359,7 +363,7 @@ uint32_t XCursorLoader::GetPreferredCurs
     return size;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Let the toolkit have the next say.
   auto* linux_ui = LinuxUi::instance();
   size = linux_ui ? linux_ui->GetCursorThemeSize() : 0;
