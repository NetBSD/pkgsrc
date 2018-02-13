$NetBSD: patch-src_libmultiple_RayleighScattering.cpp,v 1.1 2018/02/13 12:45:02 ryoon Exp $

--- src/libmultiple/RayleighScattering.cpp.orig	2012-02-25 16:32:59.000000000 +0000
+++ src/libmultiple/RayleighScattering.cpp
@@ -369,8 +369,12 @@ RayleighScattering::readConfigFile(strin
 
     diskTemplate_.clear();
     limbTemplate_.clear();
-    while (inFile.getline(line, MAX_LINE_LENGTH, '\n') != NULL)
+    while (1)
     {
+        inFile.getline(line, MAX_LINE_LENGTH, '\n');
+	if (inFile.eof() || inFile.fail())
+	    break;
+
         int i = 0;
         while (isDelimiter(line[i]))
         {
@@ -439,8 +443,12 @@ RayleighScattering::readBlock(ifstream &
     values.clear();
 
     char line[MAX_LINE_LENGTH];
-    while (inFile.getline(line, MAX_LINE_LENGTH, '\n') != NULL)
+    while (1)
     {
+        inFile.getline(line, MAX_LINE_LENGTH, '\n');
+	if (inFile.eof() || inFile.fail())
+	    break;
+
         int i = 0;
         while (isDelimiter(line[i]))
         {
@@ -470,8 +478,12 @@ RayleighScattering::readValue(ifstream &
                               double &value)
 {
     char line[MAX_LINE_LENGTH];
-    while (inFile.getline(line, MAX_LINE_LENGTH, '\n') != NULL)
+    while (1)
     {
+        inFile.getline(line, MAX_LINE_LENGTH, '\n');
+	if (inFile.eof() || inFile.fail())
+	    break;
+
         int i = 0;
         while (isDelimiter(line[i]))
         {
