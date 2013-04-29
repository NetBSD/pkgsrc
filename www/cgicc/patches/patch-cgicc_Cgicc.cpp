$NetBSD: patch-cgicc_Cgicc.cpp,v 1.1 2013/04/29 21:28:56 joerg Exp $

--- cgicc/Cgicc.cpp.orig	2013-04-29 20:15:30.000000000 +0000
+++ cgicc/Cgicc.cpp
@@ -324,11 +324,11 @@ cgicc::Cgicc::findEntries(const std::str
   result.clear();
 
   if(byName) {
-    copy_if(fFormData.begin(), fFormData.end(), 
+    ::cgicc::copy_if(fFormData.begin(), fFormData.end(), 
 	    std::back_inserter(result),FE_nameCompare(param));
   }
   else {
-    copy_if(fFormData.begin(), fFormData.end(), 
+    ::cgicc::copy_if(fFormData.begin(), fFormData.end(), 
 	    std::back_inserter(result), FE_valueCompare(param));
   }
 
