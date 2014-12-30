$NetBSD: patch-Source_WebCore_page_NavigatorBase.cpp,v 1.1 2014/12/30 17:23:48 adam Exp $

* Treat *BSD like Linux

--- Source/WebCore/page/NavigatorBase.cpp.orig	2013-11-27 01:01:47.000000000 +0000
+++ Source/WebCore/page/NavigatorBase.cpp
@@ -30,7 +30,7 @@
 #include "NetworkStateNotifier.h"
 #include <wtf/text/WTFString.h>
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD)
 #include "sys/utsname.h"
 #include <wtf/StdLibExtras.h>
 #endif
@@ -86,7 +86,7 @@ String NavigatorBase::appVersion() const
 
 String NavigatorBase::platform() const
 {
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD)
     if (!String(WEBCORE_NAVIGATOR_PLATFORM).isEmpty())
         return WEBCORE_NAVIGATOR_PLATFORM;
     struct utsname osname;
