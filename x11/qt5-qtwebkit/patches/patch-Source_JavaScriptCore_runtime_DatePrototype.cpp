$NetBSD: patch-Source_JavaScriptCore_runtime_DatePrototype.cpp,v 1.1 2017/11/21 17:00:28 minskim Exp $

Cast ICU's UChar (char16_t) to pass as UniChar.

--- Source/JavaScriptCore/runtime/DatePrototype.cpp.orig	2015-10-13 04:37:10.000000000 +0000
+++ Source/JavaScriptCore/runtime/DatePrototype.cpp
@@ -167,7 +167,7 @@ static JSCell* formatLocaleDate(ExecStat
     CFRelease(locale);
 
     if (useCustomFormat) {
-        CFStringRef customFormatCFString = CFStringCreateWithCharacters(0, customFormatString.characters(), customFormatString.length());
+        CFStringRef customFormatCFString = CFStringCreateWithCharacters(0, (const UniChar*)customFormatString.characters(), customFormatString.length());
         CFDateFormatterSetFormat(formatter, customFormatCFString);
         CFRelease(customFormatCFString);
     }
@@ -184,7 +184,7 @@ static JSCell* formatLocaleDate(ExecStat
     ASSERT(length <= bufferLength);
     if (length > bufferLength)
         length = bufferLength;
-    CFStringGetCharacters(string, CFRangeMake(0, length), buffer);
+    CFStringGetCharacters(string, CFRangeMake(0, length), (UniChar*)buffer);
 
     CFRelease(string);
 
