$NetBSD: patch-src_imagecolors.cpp,v 1.5 2022/09/29 19:46:40 markd Exp $

Explicitly use std::pow.

--- src/imagecolors.cpp.orig	2022-09-05 12:09:26.000000000 +0000
+++ src/imagecolors.cpp
@@ -27,6 +27,8 @@
 #include <cmath>
 #include <vector>
 
+using std::pow;
+
 #define return_fallback(value)                                                                                                                                 \
     if (m_imageData.m_samples.size() == 0) {                                                                                                                   \
         return value;                                                                                                                                          \
