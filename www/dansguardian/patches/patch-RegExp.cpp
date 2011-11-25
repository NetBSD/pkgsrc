$NetBSD: patch-RegExp.cpp,v 1.1 2011/11/25 22:24:39 joerg Exp $

--- RegExp.cpp.orig	2011-11-25 17:13:26.000000000 +0000
+++ RegExp.cpp
@@ -19,6 +19,7 @@
 
 #include "RegExp.hpp"
 #include <iostream>
+#include <cstring>
 
 RegExp::RegExp()
 :imatched(false),wascompiled(false) {}
