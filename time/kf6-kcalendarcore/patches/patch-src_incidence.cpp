$NetBSD: patch-src_incidence.cpp,v 1.1 2024/05/26 13:15:44 markd Exp $

isnan not declared in scope

--- src/incidence.cpp.orig	2024-05-03 12:23:27.000000000 +0000
+++ src/incidence.cpp
@@ -1047,7 +1047,7 @@ void Incidence::setGeoLatitude(float geo
         return;
     }
 
-    if (isnan(geolatitude)) {
+    if (std::isnan(geolatitude)) {
         geolatitude = INVALID_LATLON;
     }
     if (geolatitude != INVALID_LATLON && (geolatitude < -90.0 || geolatitude > 90.0)) {
@@ -1075,7 +1075,7 @@ void Incidence::setGeoLongitude(float ge
         return;
     }
 
-    if (isnan(geolongitude)) {
+    if (std::isnan(geolongitude)) {
         geolongitude = INVALID_LATLON;
     }
     if (geolongitude != INVALID_LATLON && (geolongitude < -180.0 || geolongitude > 180.0)) {
