$NetBSD: patch-src_libannotate_addMarkers.cpp,v 1.2 2019/11/16 17:36:28 ng0 Exp $

Multiple inFile.getline() calls within xplanet test the return
against NULL in a read loop, but g++ 6 doesn't like this. Replace
with checks for inFile.eof() and inFile.fail() instead.

--- src/libannotate/addMarkers.cpp.orig	2011-11-15 01:44:24.000000000 +0000
+++ src/libannotate/addMarkers.cpp
@@ -429,12 +429,16 @@ addMarkers(PlanetProperties *planetProperties, Planet *planet,
         {
             ifstream inFile(markerFile.c_str());
             char *line = new char[MAX_LINE_LENGTH];
-            while (inFile.getline (line, MAX_LINE_LENGTH, '\n') != NULL)
+            while (1)
             {
                 unsigned char color[3];
                 memcpy(color, planetProperties->MarkerColor(), 3);
                 string font(planetProperties->MarkerFont());
                 int fontSize(planetProperties->MarkerFontSize());
+
+                inFile.getline (line, MAX_LINE_LENGTH, '\n');
+                if (inFile.eof() || inFile.fail())
+                    break;
                 
                 readMarkerFile(line, planet, pixel_radius, 
                                view, projection, width, height, 
@@ -475,13 +479,18 @@ addMarkers(View *view, const int width, const int height,
         {
             ifstream inFile(markerFile.c_str());
             char *line = new char[MAX_LINE_LENGTH];
-            while (inFile.getline (line, MAX_LINE_LENGTH, '\n') != NULL)
+            while (1)
             {
+                inFile.getline (line, MAX_LINE_LENGTH, '\n');
+
                 unsigned char color[3];
                 memcpy(color, options->Color(), 3);
                 string font(options->Font());
                 int fontSize(options->FontSize());
-                
+
+                if (inFile.eof() || inFile.fail())
+                    break;
+
                 readMarkerFile(line, NULL, 0, 
                                view, NULL, width, height, 
                                color, font, fontSize, 1.0, 
