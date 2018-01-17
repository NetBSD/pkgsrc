$NetBSD: patch-Source_WebCore_page_NavigatorBase.cpp,v 1.2 2018/01/17 19:37:33 markd Exp $

* Treat *BSD like Linux

--- Source/WebCore/page/NavigatorBase.cpp.orig	2017-06-04 20:16:06.000000000 +0000
+++ Source/WebCore/page/NavigatorBase.cpp
@@ -31,7 +31,7 @@
 #include <wtf/NeverDestroyed.h>
 #include <wtf/text/WTFString.h>
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD)
 #include "sys/utsname.h"
 #include <wtf/StdLibExtras.h>
 #endif
@@ -90,7 +90,7 @@ String NavigatorBase::appVersion() const
 
 String NavigatorBase::platform() const
 {
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD)
     if (!String(WEBCORE_NAVIGATOR_PLATFORM).isEmpty())
         return WEBCORE_NAVIGATOR_PLATFORM;
     struct utsname osname;
