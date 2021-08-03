$NetBSD: patch-src_3rdparty_chromium_content_public_common_common__param__traits__macros.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/public/common/common_param_traits_macros.h.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/common_param_traits_macros.h
@@ -315,7 +315,7 @@ IPC_STRUCT_TRAITS_BEGIN(blink::mojom::Re
   IPC_STRUCT_TRAITS_MEMBER(accept_languages)
   IPC_STRUCT_TRAITS_MEMBER(disable_client_blocked_error_page)
   IPC_STRUCT_TRAITS_MEMBER(plugin_fullscreen_allowed)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(system_font_family_name)
 #endif
 #if defined(OS_WIN)
