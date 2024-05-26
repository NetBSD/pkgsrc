$NetBSD: patch-src_imagecolors.cpp,v 1.1 2024/05/26 13:34:10 markd Exp $

Explicitly use std::pow.

--- src/imagecolors.cpp.orig	2023-07-01 09:58:54.000000000 +0000
+++ src/imagecolors.cpp
@@ -29,6 +29,8 @@
 #include <cmath>
 #include <vector>
 
+using std::pow;
+
 #include "config-OpenMP.h"
 #if HAVE_OpenMP
 #include <omp.h>
