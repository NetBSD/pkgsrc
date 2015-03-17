$NetBSD: patch-mozilla_dom_plugins_ipc_PluginModuleChild.cpp,v 1.9 2015/03/17 19:50:42 ryoon Exp $

--- mozilla/dom/plugins/ipc/PluginModuleChild.cpp.orig	2015-03-09 05:35:00.000000000 +0000
+++ mozilla/dom/plugins/ipc/PluginModuleChild.cpp
@@ -307,7 +307,7 @@ PluginModuleChild::InitForChrome(const s
 
     // TODO: use PluginPRLibrary here
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     mShutdownFunc =
         (NP_PLUGINSHUTDOWN) PR_FindFunctionSymbol(mLibrary, "NP_Shutdown");
 
@@ -1869,7 +1869,7 @@ PluginModuleChild::AnswerNP_GetEntryPoin
     AssertPluginThread();
     MOZ_ASSERT(mIsChrome);
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     *_retval = mGetEntryPointsFunc(&mFunctions);
@@ -1899,7 +1899,7 @@ PluginModuleChild::AnswerNP_Initialize(c
     SendBackUpXResources(FileDescriptor(xSocketFd));
 #endif
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     *_retval = mInitializeFunc(&sBrowserFuncs, &mFunctions);
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
