$NetBSD: patch-qtwebkit_Source_WebCore_page_NavigatorBase.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Treat *BSD like Linux

--- qtwebkit/Source/WebCore/page/NavigatorBase.cpp.orig	2013-11-27 01:01:47.000000000 +0000
+++ qtwebkit/Source/WebCore/page/NavigatorBase.cpp
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
