$NetBSD: patch-Source_WebCore_page_NavigatorBase.cpp,v 1.1 2026/08/30 14:25:05 wiz Exp $

--- Source/WebCore/page/NavigatorBase.cpp.orig	2026-02-23 14:40:55.413300800 +0000
+++ Source/WebCore/page/NavigatorBase.cpp
@@ -46,7 +46,7 @@
 #include <wtf/text/MakeString.h>
 #include <wtf/text/WTFString.h>
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(NETBSD)
 #include "sys/utsname.h"
 #include <wtf/StdLibExtras.h>
 #endif
@@ -96,7 +96,7 @@ String NavigatorBase::platform() const
 
 String NavigatorBase::platform() const
 {
-#if OS(LINUX)
+#if OS(LINUX) || OS(NETBSD)
     static NeverDestroyed<String> platformName = [] {
         struct utsname osname;
         return uname(&osname) >= 0 ? makeString(unsafeSpan(osname.sysname), " "_s, unsafeSpan(osname.machine)) : emptyString();
