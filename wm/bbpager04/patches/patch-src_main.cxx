$NetBSD: patch-src_main.cxx,v 1.1 2011/11/25 22:22:05 joerg Exp $

--- src/main.cxx.orig	2011-11-25 17:02:24.000000000 +0000
+++ src/main.cxx
@@ -24,6 +24,7 @@
 #include "config.h"
 
 #include <stdio.h>
+#include <cstring>
 #include <string>
 #include <iostream>
 
