$NetBSD: patch-src_readConfig.cpp,v 1.1 2018/02/13 12:45:02 ryoon Exp $

--- src/readConfig.cpp.orig	2012-03-03 03:20:05.000000000 +0000
+++ src/readConfig.cpp
@@ -550,9 +550,13 @@ readConfigFile(string configFile, Planet
 
         ifstream inFile(configFile.c_str());
         char *line = new char[256];
-        while (inFile.getline(line, 256, '\n') != NULL)
+	while (1)
+	{
+	    inFile.getline(line, 256, '\n');
+	    if (inFile.eof() || inFile.fail())
+	        break;
             readConfig(line, planetProperties);
-        
+        }
         // This condition will only be true if [default] is the only
         // section in the config file.  In this case, set all planet
         // properties to the default values.
