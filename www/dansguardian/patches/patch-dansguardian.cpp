$NetBSD: patch-dansguardian.cpp,v 1.1 2011/11/25 22:24:39 joerg Exp $

--- dansguardian.cpp.orig	2011-11-25 17:15:02.000000000 +0000
+++ dansguardian.cpp
@@ -24,6 +24,7 @@
 #include <iostream>
 #include <arpa/inet.h>
 #include <cstdio>
+#include <cstdlib>
 #include <string>
 #include <unistd.h>
 #include <cerrno>
