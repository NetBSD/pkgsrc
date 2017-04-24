$NetBSD: patch-Source_JavaScriptCore_API_JSStringRef.cpp,v 1.1 2017/04/24 15:40:12 wiz Exp $

Fix build with icu-59.1.

--- Source/JavaScriptCore/API/JSStringRef.cpp.orig	2016-04-10 06:48:36.000000000 +0000
+++ Source/JavaScriptCore/API/JSStringRef.cpp
@@ -37,7 +37,7 @@ using namespace WTF::Unicode;
 JSStringRef JSStringCreateWithCharacters(const JSChar* chars, size_t numChars)
 {
     initializeThreading();
-    return OpaqueJSString::create(chars, numChars).leakRef();
+    return OpaqueJSString::create((const UChar*)chars, numChars).leakRef();
 }
 
 JSStringRef JSStringCreateWithUTF8CString(const char* string)
@@ -62,7 +62,7 @@ JSStringRef JSStringCreateWithUTF8CStrin
 JSStringRef JSStringCreateWithCharactersNoCopy(const JSChar* chars, size_t numChars)
 {
     initializeThreading();
-    return OpaqueJSString::create(StringImpl::createWithoutCopying(chars, numChars)).leakRef();
+    return OpaqueJSString::create(StringImpl::createWithoutCopying((const UChar*)chars, numChars)).leakRef();
 }
 
 JSStringRef JSStringRetain(JSStringRef string)
@@ -83,7 +83,7 @@ size_t JSStringGetLength(JSStringRef str
 
 const JSChar* JSStringGetCharactersPtr(JSStringRef string)
 {
-    return string->characters();
+    return (const JSChar *)string->characters();
 }
 
 size_t JSStringGetMaximumUTF8CStringSize(JSStringRef string)
