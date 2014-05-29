$NetBSD: patch-toolkit_xre_nsAppRunner.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- toolkit/xre/nsAppRunner.cpp.orig	2014-05-06 22:56:36.000000000 +0000
+++ toolkit/xre/nsAppRunner.cpp
@@ -37,7 +37,7 @@
 #include "EventTracer.h"
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "nsVersionComparator.h"
 #include "MacLaunchHelper.h"
 #include "MacApplicationDelegate.h"
@@ -158,7 +158,7 @@
 #include <wbemidl.h>
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "nsILocalFileMac.h"
 #include "nsCommandLineServiceMac.h"
 #endif
@@ -177,7 +177,7 @@
 #include <malloc.h>
 #endif
 
-#if defined (XP_MACOSX)
+#if defined (MOZ_WIDGET_COCOA)
 #include <Carbon/Carbon.h>
 #endif
 
@@ -1072,7 +1072,7 @@ nsXULAppInfo::WriteMinidumpForException(
 NS_IMETHODIMP
 nsXULAppInfo::AppendObjCExceptionInfoToAppNotes(void* aException)
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   return CrashReporter::AppendObjCExceptionInfoToAppNotes(aException);
 #else
   return NS_ERROR_NOT_IMPLEMENTED;
@@ -1145,7 +1145,7 @@ ScopedXPCOMStartup::~ScopedXPCOMStartup(
   NS_IF_RELEASE(gNativeAppSupport);
 
   if (mServiceManager) {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // On OS X, we need a pool to catch cocoa objects that are autoreleased
     // during teardown.
     mozilla::MacAutoreleasePool pool;
@@ -1682,7 +1682,7 @@ static nsresult LaunchChild(nsINativeApp
 #if defined(MOZ_WIDGET_ANDROID)
   mozilla::widget::android::GeckoAppShell::ScheduleRestart();
 #else
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   CommandLineServiceMac::SetupMacCommandLine(gRestartArgc, gRestartArgv, true);
   uint32_t restartMode = 0;
   restartMode = gRestartMode;
@@ -1767,7 +1767,7 @@ ProfileLockedDialog(nsIFile* aProfileDir
     const char16_t* params[] = {appName.get(), appName.get()};
 
     nsXPIDLString killMessage;
-#ifndef XP_MACOSX
+#ifndef MOZ_WIDGET_COCOA
     static const char16_t kRestartNoUnlocker[] = {'r','e','s','t','a','r','t','M','e','s','s','a','g','e','N','o','U','n','l','o','c','k','e','r','\0'}; // "restartMessageNoUnlocker"
     static const char16_t kRestartUnlocker[] = {'r','e','s','t','a','r','t','M','e','s','s','a','g','e','U','n','l','o','c','k','e','r','\0'}; // "restartMessageUnlocker"
 #else
@@ -1927,7 +1927,7 @@ ShowProfileManager(nsIToolkitProfileServ
     rv = xpcom.SetWindowCreator(aNative);
     NS_ENSURE_SUCCESS(rv, NS_ERROR_FAILURE);
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     CommandLineServiceMac::SetupMacCommandLine(gRestartArgc, gRestartArgv, true);
 #endif
 
@@ -3142,7 +3142,7 @@ XREMain::XRE_mainInit(bool* aExitFlag)
   }
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (EnvHasValue("MOZ_LAUNCHED_CHILD")) {
     // This is needed, on relaunch, to force the OS to use the "Cocoa Dock
     // API".  Otherwise the call to ReceiveNextEvent() below will make it
@@ -3226,7 +3226,7 @@ XREMain::XRE_mainInit(bool* aExitFlag)
   }
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (GetCurrentEventKeyModifiers() & optionKey)
     gSafeMode = true;
 #endif
@@ -4033,7 +4033,7 @@ XREMain::XRE_mainRun()
     g_unsetenv ("DESKTOP_STARTUP_ID");
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // Set up ability to respond to system (Apple) events. This must be
     // done before setting up the command line service.
     SetupMacApplicationDelegate();
