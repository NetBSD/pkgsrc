$NetBSD: patch-mozilla_dom_plugins_ipc_PluginModuleChild.cpp,v 1.8 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/dom/plugins/ipc/PluginModuleChild.cpp.orig	2013-08-04 03:05:22.000000000 +0000
+++ mozilla/dom/plugins/ipc/PluginModuleChild.cpp
@@ -203,7 +203,7 @@ PluginModuleChild::Init(const std::strin
 
     // TODO: use PluginPRLibrary here
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     mShutdownFunc =
         (NP_PLUGINSHUTDOWN) PR_FindFunctionSymbol(mLibrary, "NP_Shutdown");
 
@@ -1834,7 +1834,7 @@ PluginModuleChild::AnswerNP_GetEntryPoin
     PLUGIN_LOG_DEBUG_METHOD;
     AssertPluginThread();
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     *_retval = mGetEntryPointsFunc(&mFunctions);
@@ -1863,7 +1863,7 @@ PluginModuleChild::AnswerNP_Initialize(c
     SendBackUpXResources(FileDescriptor(xSocketFd));
 #endif
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     *_retval = mInitializeFunc(&sBrowserFuncs, &mFunctions);
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
