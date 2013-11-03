$NetBSD: patch-dom_plugins_ipc_PluginModuleChild.cpp,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- dom/plugins/ipc/PluginModuleChild.cpp.orig	2013-05-11 19:19:27.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.cpp
@@ -201,7 +201,7 @@ PluginModuleChild::Init(const std::strin
 
     // TODO: use PluginPRLibrary here
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     mShutdownFunc =
         (NP_PLUGINSHUTDOWN) PR_FindFunctionSymbol(mLibrary, "NP_Shutdown");
 
@@ -1836,7 +1836,7 @@ PluginModuleChild::AnswerNP_GetEntryPoin
     PLUGIN_LOG_DEBUG_METHOD;
     AssertPluginThread();
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     *_retval = mGetEntryPointsFunc(&mFunctions);
@@ -1865,7 +1865,7 @@ PluginModuleChild::AnswerNP_Initialize(c
     SendBackUpXResources(FileDescriptor(xSocketFd));
 #endif
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     *_retval = mInitializeFunc(&sBrowserFuncs, &mFunctions);
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
