$NetBSD: patch-src_acl_Url.cc,v 1.1 2013/02/10 18:16:53 adam Exp $

On case-insensitive file systems acl/Url.h might get included.

--- src/acl/Url.cc.orig	2013-02-10 13:41:53.000000000 +0000
+++ src/acl/Url.cc
@@ -37,7 +37,7 @@
 #include "acl/Checklist.h"
 #include "acl/RegexData.h"
 #include "rfc1738.h"
-#include "URL.h"
+#include "../URL.h"
 
 int
 ACLUrlStrategy::match (ACLData<char const *> * &data, ACLFilledChecklist *checklist)
