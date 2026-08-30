$NetBSD: patch-Source_WebKit_UIProcess_Launcher_glib_ProcessLauncherGLib.cpp,v 1.1 2026/08/30 14:25:05 wiz Exp $

/scratch/nih/webkit-gtk/work/webkitgtk-2.46.3/Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp: In member function 'void WebKit::ProcessLauncher::launchProcess()':
/scratch/nih/webkit-gtk/work/webkitgtk-2.46.3/Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp:190:17: error: 'pidSocketString' was not declared in this scope
  190 |     argv[i++] = pidSocketString.get();
      |                 ^~~~~~~~~~~~~~~

--- Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp.orig	2025-03-11 09:29:45.656848000 +0000
+++ Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp
@@ -152,7 +152,11 @@ void ProcessLauncher::launchProcess()
     }
 
     realExecutablePath = FileSystem::fileSystemRepresentation(executablePath);
+#if OS(LINUX)
     unsigned nargs = 5; // size of the argv array for g_spawn_async()
+#else
+    unsigned nargs = 4; // size of the argv array for g_spawn_async()
+#endif
 
 #if ENABLE(DEVELOPER_MODE)
     Vector<CString> prefixArgs;
