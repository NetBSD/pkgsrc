$NetBSD: patch-src_FOptionContainer.cpp,v 1.1 2015/09/03 11:55:40 sborrill Exp $

maxuploadsize is NOT dependent upon SMTP

--- src/FOptionContainer.cpp.orig	2015-09-03 12:08:34.000000000 +0100
+++ src/FOptionContainer.cpp	2015-09-03 12:09:05.000000000 +0100
@@ -304,14 +304,6 @@
 		violationbody="";
 
 		threshold = findoptionI("threshold");
-                // TODO: Implement a "findoptionO" and a version of
-                // reality check which uses off_t, for large file support?
-                max_upload_size = findoptionI("maxuploadsize");
-                if (!realitycheck(max_upload_size, -1, 0, "maxuploadsize")) {
-                        return false;
-                }               // check its a reasonable value
-                max_upload_size *= 1024;
-
 		avadmin = findoptionS("avadmin");
 		if (avadmin.length()==0) {
 			if (notifyav==1) {
@@ -358,6 +350,14 @@
 		}
 #endif
 	   
+                // TODO: Implement a "findoptionO" and a version of
+                // reality check which uses off_t, for large file support?
+                max_upload_size = findoptionI("maxuploadsize");
+                if (!realitycheck(max_upload_size, -1, 0, "maxuploadsize")) {
+                        return false;
+                }               // check its a reasonable value
+                max_upload_size *= 1024;
+
 		// override default reporting level
 		String temp_reporting_level(findoptionS("reportinglevel"));
 		if (temp_reporting_level != "") {
