$NetBSD: patch-Makefile.PL,v 1.1 2016/06/21 13:23:32 mef Exp $

Adhoc work around not to pick the definition of CURL_DID_MEMORY_FUNC_TYPEDEFS:
./curlopt-constants.c:19:58: error: non-void function 'constant' should return a value [-Wreturn-type]
if (strEQ(name, "DID_MEMORY_FUNC_TYPEDEFS")) return CURL_DID_MEMORY_FUNC_TYPEDEFS;
^

--- Makefile.PL.orig	2016-06-21 21:55:38.000000000 +0900
+++ Makefile.PL	2016-06-21 21:57:43.000000000 +0900
@@ -127,7 +127,7 @@ if (!defined($curl_h)) {
     close H;
 
     for my $e (sort @syms) {
-       if($e =~ /(OBSOLETE|^CURL_EXTERN|_LAST\z|_LASTENTRY\z)/) {
+       if($e =~ /(OBSOLETE|^CURL_EXTERN|_LAST\z|_LASTENTRY\z|CURL_DID_MEMORY_FUNC_TYPEDEFS\z)/) {
           next;
        }
        my ($group) = $e =~ m/^([^_]+_)/;
