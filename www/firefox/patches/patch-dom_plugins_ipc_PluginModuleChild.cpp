$NetBSD: patch-dom_plugins_ipc_PluginModuleChild.cpp,v 1.4 2014/05/29 15:38:19 pho Exp $

* Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/ipc/PluginModuleChild.cpp.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.cpp
@@ -111,7 +111,7 @@ PluginModuleChild::PluginModuleChild()
     memset(&mSavedData, 0, sizeof(mSavedData));
     gInstance = this;
     mUserAgent.SetIsVoid(true);
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     mac_plugin_interposing::child::SetUpCocoaInterposing();
 #endif
 }
@@ -197,7 +197,7 @@ PluginModuleChild::Init(const std::strin
 
     // TODO: use PluginPRLibrary here
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     mShutdownFunc =
         (NP_PLUGINSHUTDOWN) PR_FindFunctionSymbol(mLibrary, "NP_Shutdown");
 
@@ -1825,7 +1825,7 @@ PluginModuleChild::AnswerNP_GetEntryPoin
     PLUGIN_LOG_DEBUG_METHOD;
     AssertPluginThread();
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     *_retval = mGetEntryPointsFunc(&mFunctions);
@@ -1854,7 +1854,7 @@ PluginModuleChild::AnswerNP_Initialize(c
     SendBackUpXResources(FileDescriptor(xSocketFd));
 #endif
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     *_retval = mInitializeFunc(&sBrowserFuncs, &mFunctions);
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
@@ -1986,7 +1986,7 @@ PluginModuleChild::InitQuirksModes(const
     }
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // Whitelist Flash and Quicktime to support offline renderer
     NS_NAMED_LITERAL_CSTRING(flash, "application/x-shockwave-flash");
     NS_NAMED_LITERAL_CSTRING(quicktime, "QuickTime Plugin.plugin");
@@ -2046,7 +2046,7 @@ PluginModuleChild::AnswerPPluginInstance
 
     childInstance->Initialize();
 
-#if defined(XP_MACOSX) && defined(__i386__)
+#if defined(MOZ_WIDGET_COCOA) && defined(__i386__)
     // If an i386 Mac OS X plugin has selected the Carbon event model then
     // we have to fail. We do not support putting Carbon event model plugins
     // out of process. Note that Carbon is the default model so out of process
