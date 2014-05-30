$NetBSD: patch-intl_locale_src_nsLocaleService.cpp,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- intl/locale/src/nsLocaleService.cpp.orig	2014-05-06 22:55:40.000000000 +0000
+++ intl/locale/src/nsLocaleService.cpp
@@ -26,7 +26,7 @@
 #  include "nsServiceManagerUtils.h"
 #  include "unidef.h"
 #  include "nsIOS2Locale.h"
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 #  include <Carbon/Carbon.h>
 #elif defined(XP_UNIX)
 #  include <locale.h>
@@ -50,7 +50,7 @@ const char* LocaleList[LocaleListLength]
 #define NSILOCALE_MAX_ACCEPT_LANGUAGE	16
 #define NSILOCALE_MAX_ACCEPT_LENGTH		18
 
-#if (defined(XP_UNIX) && !defined(XP_MACOSX)) || defined(XP_OS2)
+#if (defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)) || defined(XP_OS2)
 static int posix_locale_category[LocaleListLength] =
 {
   LC_COLLATE,
@@ -122,7 +122,7 @@ nsLocaleService::nsLocaleService(void) 
     rv = NewLocale(xpLocale, getter_AddRefs(mApplicationLocale));
     NS_ENSURE_SUCCESS_VOID(rv);
 #endif
-#if defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
     nsRefPtr<nsLocale> resultLocale(new nsLocale());
     NS_ENSURE_TRUE_VOID(resultLocale);
 
@@ -215,7 +215,7 @@ nsLocaleService::nsLocaleService(void) 
     }  // if ( NS_SUCCEEDED )...
 #endif  // XP_OS2
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // Get string representation of user's current locale
     CFLocaleRef userLocaleRef = ::CFLocaleCopyCurrent();
     CFStringRef userLocaleStr = ::CFLocaleGetIdentifier(userLocaleRef);
@@ -243,7 +243,7 @@ nsLocaleService::nsLocaleService(void) 
     ::CFRelease(userLocaleRef);
 
     NS_ASSERTION(mApplicationLocale, "Failed to create locale objects");
-#endif // XP_MACOSX
+#endif // MOZ_WIDGET_COCOA
 }
 
 nsLocaleService::~nsLocaleService(void)
@@ -266,7 +266,7 @@ nsLocaleService::NewLocale(const nsAStri
       NS_ConvertASCIItoUTF16 category(LocaleList[i]);
       result = resultLocale->AddCategory(category, aLocale);
       if (NS_FAILED(result)) return result;
-#if defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
       category.AppendLiteral("##PLATFORM");
       result = resultLocale->AddCategory(category, aLocale);
       if (NS_FAILED(result)) return result;
