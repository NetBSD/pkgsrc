$NetBSD: patch-src_imagecolors.cpp,v 1.4 2022/04/25 17:58:29 tnn Exp $

Explicitly use std::pow.

--- src/imagecolors.cpp.orig	2022-04-02 10:23:09.000000000 +0000
+++ src/imagecolors.cpp
@@ -26,6 +26,8 @@
 #include "loggingcategory.h"
 #include <cmath>
 
+using std::pow;
+
 #define return_fallback(value)                                                                                                                                 \
     if (m_imageData.m_samples.size() == 0) {                                                                                                                   \
         return value;                                                                                                                                          \
