$NetBSD: patch-mozilla_netwerk_protocol_http_Http2Session.cpp,v 1.2 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/netwerk/protocol/http/Http2Session.cpp.orig	2015-09-25 07:36:06.000000000 +0000
+++ mozilla/netwerk/protocol/http/Http2Session.cpp
@@ -33,7 +33,6 @@
 #include "nsStandardURL.h"
 #include "nsURLHelper.h"
 #include "prprf.h"
-#include "prnetdb.h"
 #include "sslt.h"
 
 #ifdef DEBUG
