$NetBSD: patch-ListContainer.cpp,v 1.1 2011/11/25 22:24:39 joerg Exp $

--- ListContainer.cpp.orig	2011-11-25 17:14:09.000000000 +0000
+++ ListContainer.cpp
@@ -24,6 +24,7 @@
 #include "RegExp.hpp"
 #include <cstdlib>
 #include <cstdio>
+#include <cstring>
 #include <unistd.h>
 #include "String.hpp"
 #include <iostream>
