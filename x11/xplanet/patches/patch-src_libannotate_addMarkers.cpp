$NetBSD: patch-src_libannotate_addMarkers.cpp,v 1.1 2018/02/13 12:45:02 ryoon Exp $

--- src/libannotate/addMarkers.cpp.orig	2011-11-15 01:44:24.000000000 +0000
+++ src/libannotate/addMarkers.cpp
@@ -423,13 +423,16 @@ addMarkers(PlanetProperties *planetPrope
         {
             ifstream inFile(markerFile.c_str());
             char *line = new char[MAX_LINE_LENGTH];
-            while (inFile.getline (line, MAX_LINE_LENGTH, '\n') != NULL)
+	    while (1)
             {
                 unsigned char color[3];
                 memcpy(color, planetProperties->MarkerColor(), 3);
                 string font(planetProperties->MarkerFont());
                 int fontSize(planetProperties->MarkerFontSize());
                 
+		inFile.getline (line, MAX_LINE_LENGTH, '\n');
+ 		if (inFile.eof() || inFile.fail())
+		    break;
                 readMarkerFile(line, planet, pixel_radius, X, Y, Z, 
                                view, projection, width, height, 
                                color, font, fontSize, 
@@ -469,13 +472,18 @@ addMarkers(View *view, const int width, 
         {
             ifstream inFile(markerFile.c_str());
             char *line = new char[MAX_LINE_LENGTH];
-            while (inFile.getline (line, MAX_LINE_LENGTH, '\n') != NULL)
-            {
+	    while (1)
+	    {
+		inFile.getline (line, MAX_LINE_LENGTH, '\n');
+
                 unsigned char color[3];
                 memcpy(color, options->Color(), 3);
                 string font(options->Font());
                 int fontSize(options->FontSize());
                 
+ 		if (inFile.eof() || inFile.fail())
+		    break;
+
                 readMarkerFile(line, NULL, 0, 0, 0, 0,
                                view, NULL, width, height, 
                                color, font, fontSize, 1.0, 
