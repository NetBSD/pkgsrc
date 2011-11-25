$NetBSD: patch-FOptionContainer.cpp,v 1.1 2011/11/25 22:24:39 joerg Exp $

--- FOptionContainer.cpp.orig	2011-11-25 17:14:40.000000000 +0000
+++ FOptionContainer.cpp
@@ -22,6 +22,7 @@
 #include "FOptionContainer.hpp"
 #include "OptionContainer.hpp"
 #include "RegExp.hpp"
+#include <cstdlib>
 #include <string>
 #include <iostream>
 #include <fstream>
