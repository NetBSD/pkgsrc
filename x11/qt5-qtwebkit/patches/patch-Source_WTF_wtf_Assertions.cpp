$NetBSD: patch-Source_WTF_wtf_Assertions.cpp,v 1.2 2018/01/17 19:37:33 markd Exp $

* Add NetBSD support

--- Source/WTF/wtf/Assertions.cpp.orig	2017-06-04 20:16:06.000000000 +0000
+++ Source/WTF/wtf/Assertions.cpp
@@ -68,7 +68,7 @@
 #include <unistd.h>
 #endif
 
-#if OS(DARWIN) || (OS(LINUX) && defined(__GLIBC__) && !defined(__UCLIBC__))
+#if OS(DARWIN) || OS(NETBSD) || (OS(LINUX) && defined(__GLIBC__) && !defined(__UCLIBC__))
 #include <cxxabi.h>
 #include <dlfcn.h>
 #include <execinfo.h>
@@ -225,7 +225,7 @@ void WTFReportArgumentAssertionFailure(c
 
 void WTFGetBacktrace(void** stack, int* size)
 {
-#if OS(DARWIN) || (OS(LINUX) && defined(__GLIBC__) && !defined(__UCLIBC__))
+#if OS(DARWIN) || OS(NETBSD) || (OS(LINUX) && defined(__GLIBC__) && !defined(__UCLIBC__))
     *size = backtrace(stack, *size);
 #elif OS(WINDOWS)
     // The CaptureStackBackTrace function is available in XP, but it is not defined
@@ -259,7 +259,7 @@ void WTFReportBacktrace()
     WTFPrintBacktrace(samples + framesToSkip, frames - framesToSkip);
 }
 
-#if OS(DARWIN) || OS(LINUX)
+#if OS(DARWIN) || OS(LINUX) || OS(NETBSD)
 #  if PLATFORM(QT) || PLATFORM(GTK)
 #    if defined(__GLIBC__) && !defined(__UCLIBC__)
 #      define USE_BACKTRACE_SYMBOLS 1
