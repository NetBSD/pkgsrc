$NetBSD: patch-src_3rdparty_webkit_Source_WebCore_platform_DefaultLocalizationStrategy.cpp,v 1.2 2012/02/26 22:16:16 adam Exp $

Fix C++ error.

--- src/3rdparty/webkit/Source/WebCore/platform/DefaultLocalizationStrategy.cpp.orig	2012-01-12 19:51:48.000000000 +0100
+++ src/3rdparty/webkit/Source/WebCore/platform/DefaultLocalizationStrategy.cpp	2012-01-12 20:07:06.000000000 +0100
@@ -59,7 +59,11 @@
     return result.get();
 #elif PLATFORM(QT)
     va_list arguments;
+#ifdef __clang__
+    va_start(arguments, format.charactersWithNullTermination());
+#else
     va_start(arguments, format);
+#endif
     QString result;
     result.vsprintf(format.latin1().data(), arguments);
     va_end(arguments);
