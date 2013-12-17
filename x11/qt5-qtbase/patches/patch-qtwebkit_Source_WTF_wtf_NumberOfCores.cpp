$NetBSD: patch-qtwebkit_Source_WTF_wtf_NumberOfCores.cpp,v 1.2 2013/12/17 23:22:35 joerg Exp $

* Add NetBSD support

--- qtwebkit/Source/WTF/wtf/NumberOfCores.cpp.orig	2013-12-08 17:09:59.000000000 +0000
+++ qtwebkit/Source/WTF/wtf/NumberOfCores.cpp
@@ -32,6 +32,7 @@
 // data types defined in the former. See sysctl(3) and style(9).
 #include <sys/types.h>
 #include <sys/sysctl.h>
+#include <unistd.h>
 #elif OS(LINUX) || OS(AIX) || OS(SOLARIS)
 #include <unistd.h>
 #elif OS(WINDOWS)
@@ -50,7 +51,7 @@ int numberOfProcessorCores()
     if (s_numberOfCores > 0)
         return s_numberOfCores;
 
-#if OS(DARWIN) || OS(OPENBSD) || OS(NETBSD) || OS(FREEBSD)
+#if OS(DARWIN) || OS(OPENBSD) || OS(FREEBSD)
     unsigned result;
     size_t length = sizeof(result);
     int name[] = {
@@ -60,7 +61,7 @@ int numberOfProcessorCores()
     int sysctlResult = sysctl(name, sizeof(name) / sizeof(int), &result, &length, 0, 0);
 
     s_numberOfCores = sysctlResult < 0 ? defaultIfUnavailable : result;
-#elif OS(LINUX) || OS(AIX) || OS(SOLARIS)
+#elif OS(LINUX) || OS(AIX) || OS(SOLARIS) || OS(NETBSD)
     long sysconfResult = sysconf(_SC_NPROCESSORS_ONLN);
 
     s_numberOfCores = sysconfResult < 0 ? defaultIfUnavailable : static_cast<int>(sysconfResult);
