$NetBSD: patch-src_filterrtf.cpp,v 1.1 2020/07/30 02:13:56 scole Exp $

Use wchar functions available on NetBSD

--- src/filterrtf.cpp.orig	2018-08-14 05:33:16.000000000 +0000
+++ src/filterrtf.cpp
@@ -3,6 +3,7 @@
 //////////////////////////////////////////////////////////////////////
 #include <string.h>
 #include <ctype.h>
+#include <wchar.h>
 #include <wctype.h>
 #include "filterrtf.h"
 #include "conv/utf8.h"
@@ -109,7 +110,7 @@ FilterRTF::GetNextToken (wchar_t* token,
     {
       *thaiFlag = isThaiUni (strbuff[0]);
       nCopy = min<int> (tokenSz - 1, wcslen (strbuff));
-      token = wcpncpy (token, strbuff, nCopy);
+      token = wcsncpy (token, strbuff, nCopy);
       *token = 0;
       tokenSz -= nCopy;
       wmemmove (strbuff, strbuff + nCopy, wcslen (strbuff + nCopy) + 1);
@@ -155,7 +156,7 @@ FilterRTF::GetNextToken (wchar_t* token,
                     int len = strlen (rtfToken.getVal());
                     if (len + 2 <= tokenSz - 1)
                       {
-                        token = wcpcpy (token, L"\\u");
+                        token = wcscpy (token, L"\\u");
                         token = Ascii2WcsCopy (token, rtfToken.getVal());
                         tokenSz -= len + 2;
                       }
@@ -177,7 +178,7 @@ FilterRTF::GetNextToken (wchar_t* token,
                       int len = strlen (rtfToken.getVal());
                       if (len + 2 <= tokenSz - 1)
                         {
-                          token = wcpcpy (token, L"\\'");
+                          token = wcscpy (token, L"\\'");
                           token = Ascii2WcsCopy (token, rtfToken.getVal());
                           tokenSz -= len + 2;
                         }
@@ -251,7 +252,7 @@ thai_flag_determined:
                 else
                   {
                     // non-Thai text is found -> prepare to stop
-                    wchar_t* p = wcpcpy (strbuff, L"\\u");
+                    wchar_t* p = wcscpy (strbuff, L"\\u");
                     Ascii2WcsCopy (p, rtfToken.getVal());
                     isCopySkipBytes = true;
                   }
@@ -339,7 +340,7 @@ thai_flag_determined:
                     int len = strlen (rtfToken.getVal());
                     if (len + 2 <= tokenSz - 1)
                       {
-                        token = wcpcpy (token, L"\\u");
+                        token = wcscpy (token, L"\\u");
                         token = Ascii2WcsCopy (token, rtfToken.getVal());
                         tokenSz -= len + 2;
                       }
@@ -359,7 +360,7 @@ thai_flag_determined:
                       int len = strlen (rtfToken.getVal());
                       if (len + 2 <= tokenSz - 1)
                         {
-                          token = wcpcpy (token, L"\\'");
+                          token = wcscpy (token, L"\\'");
                           token = Ascii2WcsCopy (token, rtfToken.getVal());
                           tokenSz -= len + 2;
                         }
