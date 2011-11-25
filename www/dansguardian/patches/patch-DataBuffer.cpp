$NetBSD: patch-DataBuffer.cpp,v 1.1 2011/11/25 22:24:39 joerg Exp $

--- DataBuffer.cpp.orig	2011-11-25 17:12:27.000000000 +0000
+++ DataBuffer.cpp
@@ -22,6 +22,7 @@
 #include <algorithm>
 #include "DataBuffer.hpp"
 #include <cstdlib>
+#include <cstring>
 #include <unistd.h>
 #include <zlib.h>
 #include <cerrno>
