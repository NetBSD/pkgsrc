$NetBSD: patch-src_libannotate_addSatellites.cpp,v 1.1 2018/02/13 12:45:02 ryoon Exp $

--- src/libannotate/addSatellites.cpp.orig	2010-07-30 21:49:06.000000000 +0000
+++ src/libannotate/addSatellites.cpp
@@ -488,11 +488,23 @@ loadSatelliteVector(PlanetProperties *pl
         {
             ifstream inFile(tleFile.c_str());
             char lines[3][80];
-            while (inFile.getline(lines[0], 80) != NULL)
-            {
-                if ((inFile.getline(lines[1], 80) == NULL) 
-                    || (inFile.getline(lines[2], 80) == NULL))
-                {
+	    bool malformed_file = false;
+	    while (1)
+	    {
+                inFile.getline(lines[0], 80);
+ 		if (inFile.eof() || inFile.fail())
+		    break;
+		inFile.getline(lines[1], 80);
+ 		if (inFile.eof() || inFile.fail())
+		    malformed_file = true;
+		else
+		{
+                    inFile.getline(lines[2], 80);
+		    if (inFile.eof() || inFile.fail())
+		        malformed_file = true;
+                }
+		if (malformed_file)
+		{
                     ostringstream errStr;
                     errStr << "Malformed TLE file (" << tleFile << ")?\n";
                     xpWarn(errStr.str(), __FILE__, __LINE__);
@@ -542,10 +554,14 @@ addSatellites(PlanetProperties *planetPr
         {
             ifstream inFile(satFile.c_str());
             char *line = new char[MAX_LINE_LENGTH];
-            while (inFile.getline (line, MAX_LINE_LENGTH, '\n') != NULL)
+	    while (1)
+	    {
+		inFile.getline (line, MAX_LINE_LENGTH, '\n');
+ 		if (inFile.eof() || inFile.fail())
+		    break;
                 readSatelliteFile(line, planet, view, projection,
                                   planetProperties, annotationMap);
-            
+            }
             inFile.close();
             delete [] line;
         }
