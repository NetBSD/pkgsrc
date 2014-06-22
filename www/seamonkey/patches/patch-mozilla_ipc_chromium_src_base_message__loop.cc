$NetBSD: patch-mozilla_ipc_chromium_src_base_message__loop.cc,v 1.8 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/ipc/chromium/src/base/message_loop.cc.orig	2014-06-13 00:46:08.000000000 +0000
+++ mozilla/ipc/chromium/src/base/message_loop.cc
@@ -14,20 +14,18 @@
 #include "base/string_util.h"
 #include "base/thread_local.h"
 
-#if defined(OS_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #include "base/message_pump_mac.h"
 #endif
 #if defined(OS_POSIX)
 #include "base/message_pump_libevent.h"
 #endif
-#if defined(OS_LINUX) || defined(OS_BSD)
 #if defined(MOZ_WIDGET_GTK)
 #include "base/message_pump_glib.h"
 #endif
 #ifdef MOZ_WIDGET_QT
 #include "base/message_pump_qt.h"
 #endif
-#endif
 #ifdef ANDROID
 #include "base/message_pump_android.h"
 #endif
@@ -135,9 +133,9 @@ MessageLoop::MessageLoop(Type type)
   }
 #elif defined(OS_POSIX)
   if (type_ == TYPE_UI) {
-#if defined(OS_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     pump_ = base::MessagePumpMac::Create();
-#elif defined(OS_LINUX) || defined(OS_BSD)
+#elif defined(MOZ_WIDGET_GTK) || defined(MOZ_WIDGET_QT)
     pump_ = new base::MessagePumpForUI();
 #endif  // OS_LINUX
   } else if (type_ == TYPE_IO) {
