$NetBSD: patch-src_acl_DomainData.cc,v 1.1 2013/02/10 18:16:53 adam Exp $

On case-insensitive file systems acl/Url.h might get included.

--- src/acl/DomainData.cc.orig	2013-02-10 13:30:18.000000000 +0000
+++ src/acl/DomainData.cc
@@ -38,7 +38,7 @@
 #include "cache_cf.h"
 #include "Debug.h"
 #include "wordlist.h"
-#include "URL.h"
+#include "../URL.h"
 
 template<class T>
 inline void
