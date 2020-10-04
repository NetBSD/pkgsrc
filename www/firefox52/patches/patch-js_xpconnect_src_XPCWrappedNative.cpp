$NetBSD: patch-js_xpconnect_src_XPCWrappedNative.cpp,v 1.1.2.2 2020/10/04 18:31:37 bsiegert Exp $

Avoid error when compiling with gcc 9:
XPCWrappedNative.cpp:2221:41: error: '%s' directive argument is null [-Werror=format-overflow=]
 2221 |                 name = JS_sprintf_append(name, fmt,
      |                        ~~~~~~~~~~~~~~~~~^~~~~~~~~~~
 2222 |                                          array[i]->GetNameString());
      |                                          ~~~~~~~~~~~~~~~~~~~~~~~~~~


--- js/xpconnect/src/XPCWrappedNative.cpp.orig	2018-06-21 20:53:54.000000000 +0200
+++ js/xpconnect/src/XPCWrappedNative.cpp	2020-09-30 06:58:32.859731786 +0200
@@ -2218,8 +2218,10 @@ XPCWrappedNative::ToString(XPCWrappedNat
                 const char* fmt = (i == 0) ?
                                     "(%s" : (i == count-1) ?
                                         ", %s)" : ", %s";
-                name = JS_sprintf_append(name, fmt,
-                                         array[i]->GetNameString());
+		const char *s = array[i]->GetNameString();
+		if (s == NULL)
+			s = "-";
+                name = JS_sprintf_append(name, fmt, s);
             }
         }
     }
