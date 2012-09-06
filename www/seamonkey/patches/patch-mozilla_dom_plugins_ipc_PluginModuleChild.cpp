$NetBSD: patch-mozilla_dom_plugins_ipc_PluginModuleChild.cpp,v 1.4 2012/09/06 12:08:51 ryoon Exp $

--- mozilla/dom/plugins/ipc/PluginModuleChild.cpp.orig	2012-08-27 04:49:08.000000000 +0000
+++ mozilla/dom/plugins/ipc/PluginModuleChild.cpp
@@ -5,6 +5,7 @@
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 #ifdef MOZ_WIDGET_QT
+#include <unistd.h> // for _exit()
 #include <QtCore/QTimer>
 #include "nsQAppInstance.h"
 #include "NestedLoopTimer.h"
@@ -192,7 +193,7 @@ PluginModuleChild::Init(const std::strin
 
     // TODO: use PluginPRLibrary here
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     mShutdownFunc =
         (NP_PLUGINSHUTDOWN) PR_FindFunctionSymbol(mLibrary, "NP_Shutdown");
 
@@ -1811,7 +1812,7 @@ PluginModuleChild::AnswerNP_GetEntryPoin
     PLUGIN_LOG_DEBUG_METHOD;
     AssertPluginThread();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     *_retval = mGetEntryPointsFunc(&mFunctions);
@@ -1840,7 +1841,7 @@ PluginModuleChild::AnswerNP_Initialize(c
     SendBackUpXResources(FileDescriptor(xSocketFd, false/*don't close*/));
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     *_retval = mInitializeFunc(&sBrowserFuncs, &mFunctions);
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
