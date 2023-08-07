$NetBSD: patch-gfx_skia_skia_src_gpu_GrAutoLocaleSetter.h,v 1.1 2023/08/07 19:25:44 abs Exp $

NetBSD does not have uselocale(3)

--- gfx/skia/skia/src/gpu/GrAutoLocaleSetter.h.orig	2023-07-18 16:18:58.000000000 +0000
+++ gfx/skia/skia/src/gpu/GrAutoLocaleSetter.h
@@ -28,7 +28,7 @@ public:
 #if defined(SK_BUILD_FOR_WIN)
         fOldPerThreadLocale = _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
         fOldLocale = setlocale(LC_ALL, name);
-#elif !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__)
+#elif !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) && !defined(__NetBSD__)
         fLocale = newlocale(LC_ALL, name, 0);
         if (fLocale) {
             fOldLocale = uselocale(fLocale);
@@ -44,7 +44,7 @@ public:
 #if defined(SK_BUILD_FOR_WIN)
         setlocale(LC_ALL, fOldLocale);
         _configthreadlocale(fOldPerThreadLocale);
-#elif !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__)
+#elif !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) && !defined(__NetBSD__)
         if (fLocale) {
              uselocale(fOldLocale);
              freelocale(fLocale);
@@ -56,7 +56,7 @@ private:
 #if defined(SK_BUILD_FOR_WIN)
     int fOldPerThreadLocale;
     const char* fOldLocale;
-#elif !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__)
+#elif !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) && !defined(__NetBSD__)
     locale_t fOldLocale;
     locale_t fLocale;
 #endif
