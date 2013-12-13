$NetBSD: patch-qtwebkit_Source_WTF_wtf_Assertions.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add NetBSD support

--- qtwebkit/Source/WTF/wtf/Assertions.cpp.orig	2013-11-27 01:01:21.000000000 +0000
+++ qtwebkit/Source/WTF/wtf/Assertions.cpp
@@ -61,7 +61,7 @@
 #include <windows.h>
 #endif
 
-#if (OS(DARWIN) || (OS(LINUX) && !defined(__UCLIBC__))) && !OS(ANDROID)
+#if (OS(DARWIN) || OS(NETBSD) || (OS(LINUX) && !defined(__UCLIBC__))) && !OS(ANDROID)
 #include <cxxabi.h>
 #include <dlfcn.h>
 #include <execinfo.h>
@@ -245,7 +245,7 @@ void WTFReportArgumentAssertionFailure(c
 
 void WTFGetBacktrace(void** stack, int* size)
 {
-#if (OS(DARWIN) || (OS(LINUX) && !defined(__UCLIBC__))) && !OS(ANDROID)
+#if (OS(DARWIN) || (OS_NETBSD) || (OS(LINUX) && !defined(__UCLIBC__))) && !OS(ANDROID)
     *size = backtrace(stack, *size);
 #elif OS(WINDOWS) && !OS(WINCE)
     // The CaptureStackBackTrace function is available in XP, but it is not defined
@@ -279,7 +279,7 @@ void WTFReportBacktrace()
     WTFPrintBacktrace(samples + framesToSkip, frames - framesToSkip);
 }
 
-#if OS(DARWIN) || OS(LINUX)
+#if OS(DARWIN) || OS(LINUX) || OS(NETBSD)
 #  if PLATFORM(QT) || PLATFORM(GTK)
 #    if defined(__GLIBC__) && !defined(__UCLIBC__)
 #      define WTF_USE_BACKTRACE_SYMBOLS 1
