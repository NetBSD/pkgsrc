$NetBSD: patch-Source_WebKit_Platform_classifier_ResourceLoadStatisticsClassifier.cpp,v 1.1 2018/05/16 18:55:45 jperkin Exp $

Avoid ambiguous function call.

--- Source/WebKit/Platform/classifier/ResourceLoadStatisticsClassifier.cpp.orig	2018-02-20 07:38:30.000000000 +0000
+++ Source/WebKit/Platform/classifier/ResourceLoadStatisticsClassifier.cpp
@@ -29,6 +29,8 @@
 #include "Logging.h"
 #include <WebCore/ResourceLoadStatistics.h>
 
+using std::sqrt;
+
 namespace WebKit {
 using namespace WebCore;
 
