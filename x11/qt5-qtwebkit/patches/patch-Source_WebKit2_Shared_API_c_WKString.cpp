$NetBSD: patch-Source_WebKit2_Shared_API_c_WKString.cpp,v 1.1 2017/04/26 10:27:43 wiz Exp $

Fix build with icu-59.

--- Source/WebKit2/Shared/API/c/WKString.cpp.orig	2015-10-13 04:37:12.000000000 +0000
+++ Source/WebKit2/Shared/API/c/WKString.cpp
@@ -55,7 +55,7 @@ size_t WKStringGetLength(WKStringRef str
 size_t WKStringGetCharacters(WKStringRef stringRef, WKChar* buffer, size_t bufferLength)
 {
     COMPILE_ASSERT(sizeof(WKChar) == sizeof(UChar), WKStringGetCharacters_sizeof_WKChar_matches_UChar);
-    return (toImpl(stringRef)->getCharacters(static_cast<UChar*>(buffer), bufferLength));
+    return (toImpl(stringRef)->getCharacters((UChar*)(buffer), bufferLength));
 }
 
 size_t WKStringGetMaximumUTF8CStringSize(WKStringRef stringRef)
