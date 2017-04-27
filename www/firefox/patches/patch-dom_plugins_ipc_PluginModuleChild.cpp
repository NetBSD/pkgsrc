$NetBSD: patch-dom_plugins_ipc_PluginModuleChild.cpp,v 1.9 2017/04/27 01:49:47 ryoon Exp $

* Support Solaris

--- dom/plugins/ipc/PluginModuleChild.cpp.orig	2017-04-11 04:15:22.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.cpp
@@ -289,7 +289,7 @@ PluginModuleChild::InitForChrome(const s
 
     // TODO: use PluginPRLibrary here
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     mShutdownFunc =
         (NP_PLUGINSHUTDOWN) PR_FindFunctionSymbol(mLibrary, "NP_Shutdown");
 
@@ -1851,7 +1851,7 @@ PluginModuleChild::AnswerNP_GetEntryPoin
     AssertPluginThread();
     MOZ_ASSERT(mIsChrome);
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     return IPC_OK();
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     *_retval = mGetEntryPointsFunc(&mFunctions);
@@ -1899,7 +1899,7 @@ PluginModuleChild::DoNP_Initialize(const
 #endif
 
     NPError result;
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     result = mInitializeFunc(&sBrowserFuncs, &mFunctions);
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     result = mInitializeFunc(&sBrowserFuncs);
