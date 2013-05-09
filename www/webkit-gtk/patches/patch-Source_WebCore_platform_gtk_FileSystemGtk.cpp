$NetBSD: patch-Source_WebCore_platform_gtk_FileSystemGtk.cpp,v 1.1 2013/05/09 14:04:42 joerg Exp $

--- Source/WebCore/platform/gtk/FileSystemGtk.cpp.orig	2012-11-23 20:12:17.000000000 +0000
+++ Source/WebCore/platform/gtk/FileSystemGtk.cpp
@@ -222,7 +222,7 @@ CString sharedResourcesPath()
     GOwnPtr<gchar> runtimeDir(g_win32_get_package_installation_directory_of_module(hmodule));
     GOwnPtr<gchar> dataPath(g_build_filename(runtimeDir.get(), "share", "webkitgtk-"WEBKITGTK_API_VERSION_STRING, NULL));
 #else
-    GOwnPtr<gchar> dataPath(g_build_filename(DATA_DIR, "webkitgtk-"WEBKITGTK_API_VERSION_STRING, NULL));
+    GOwnPtr<gchar> dataPath(g_build_filename(DATA_DIR, "webkitgtk-" WEBKITGTK_API_VERSION_STRING, NULL));
 #endif
 
     cachedPath = dataPath.get();
