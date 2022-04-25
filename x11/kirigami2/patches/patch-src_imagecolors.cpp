$NetBSD: patch-src_imagecolors.cpp,v 1.3 2022/04/25 13:36:38 tnn Exp $

Explicitly use std::pow.

--- src/imagecolors.cpp.orig	2021-03-06 16:26:33.000000000 +0000
+++ src/imagecolors.cpp
@@ -25,6 +25,8 @@
 
 #include <cmath>
 
+using std::pow;
+
 #define return_fallback(value) if (m_imageData.m_samples.size() == 0) {\
     return value;\
 }
