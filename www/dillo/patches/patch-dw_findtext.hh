$NetBSD: patch-dw_findtext.hh,v 1.1.2.2 2026/02/18 17:01:00 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- dw/findtext.hh.orig	2025-01-18 10:51:30.000000000 +0000
+++ dw/findtext.hh
@@ -5,7 +5,7 @@
 #   error Do not include this file directly, use "core.hh" instead.
 #endif
 
-#include <ctype.h>
+#include "dlib/dlib.h"
 
 namespace dw {
 namespace core {
@@ -66,8 +66,8 @@ private:
    bool search0 (bool backwards, bool firstTrial);
 
    inline static bool charsEqual (char c1, char c2, bool caseSens)
-   { return caseSens ? c1 == c2 : tolower (c1) == tolower (c2) ||
-      (isspace (c1) && isspace (c2)); }
+   { return caseSens ? c1 == c2 : dTolower (c1) == dTolower (c2) ||
+      (dIsspace (c1) && dIsspace (c2)); }
 
 public:
    FindtextState ();
