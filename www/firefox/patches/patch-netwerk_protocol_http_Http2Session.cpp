$NetBSD: patch-netwerk_protocol_http_Http2Session.cpp,v 1.5 2015/08/11 23:48:18 ryoon Exp $

https://bugzilla.mozilla.org/show_bug.cgi?id=1130822
Fix obivous alignment issues (causing crashes on some architectures).

--- netwerk/protocol/http/Http2Session.cpp.orig	2015-08-07 15:54:20.000000000 +0000
+++ netwerk/protocol/http/Http2Session.cpp
@@ -33,7 +33,6 @@
 #include "nsStandardURL.h"
 #include "nsURLHelper.h"
 #include "prprf.h"
-#include "prnetdb.h"
 #include "sslt.h"
 
 #ifdef DEBUG
