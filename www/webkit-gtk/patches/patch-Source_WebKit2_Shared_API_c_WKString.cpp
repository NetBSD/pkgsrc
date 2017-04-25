$NetBSD: patch-Source_WebKit2_Shared_API_c_WKString.cpp,v 1.1 2017/04/25 10:37:26 wiz Exp $

Fix build with icu-59.

--- Source/WebKit2/Shared/API/c/WKString.cpp.orig	2016-08-22 12:21:08.000000000 +0000
+++ Source/WebKit2/Shared/API/c/WKString.cpp
@@ -61,7 +61,7 @@ size_t WKStringGetCharacters(WKStringRef
     unsigned unsignedBufferLength = std::min<size_t>(bufferLength, std::numeric_limits<unsigned>::max());
     auto substring = toImpl(stringRef)->stringView().substring(0, unsignedBufferLength);
 
-    substring.getCharactersWithUpconvert(static_cast<UChar*>(buffer));
+    substring.getCharactersWithUpconvert((UChar*)(buffer));
     return substring.length();
 }
 
