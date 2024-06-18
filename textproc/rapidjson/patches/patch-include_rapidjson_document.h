$NetBSD: patch-include_rapidjson_document.h,v 1.1 2024/06/18 10:06:21 markd Exp $

From Fedora
From 1257fe9096b70cc278f9d6e4029776b50df5d5cf Mon Sep 17 00:00:00 2001
From: Janusz Chorko <janusz.chorko@apdu.pl>
Date: Fri, 26 Aug 2016 21:17:38 +0200
Subject: [PATCH 1/7] Removed non-compiling assignment operator. Fixed #718

From f9d9e50caca4673f194115b059fe5daef77163fd Mon Sep 17 00:00:00 2001
From: Janusz Chorko <janusz.chorko@apdu.pl>
Date: Fri, 26 Aug 2016 21:26:50 +0200
Subject: [PATCH 2/7] Explicitly disable copy assignment operator

diff --git a/include/rapidjson/document.h b/include/rapidjson/document.h
index e3e20dfb..b0f1f70b 100644
--- include/rapidjson/document.h
+++ include/rapidjson/document.h
@@ -316,8 +316,6 @@ struct GenericStringRef {
 
     GenericStringRef(const GenericStringRef& rhs) : s(rhs.s), length(rhs.length) {}
 
-    GenericStringRef& operator=(const GenericStringRef& rhs) { s = rhs.s; length = rhs.length; }
-
     //! implicit conversion to plain CharType pointer
     operator const Ch *() const { return s; }

@@ -326,6 +324,8 @@ private:
     //! Disallow construction from non-const array
     template<SizeType N>
     GenericStringRef(CharType (&str)[N]) /* = delete */;
+    //! Copy assignment operator not permitted - immutable type
+    GenericStringRef& operator=(const GenericStringRef& rhs) /* = delete */;
 };
 
 //! Mark a character pointer as constant string
