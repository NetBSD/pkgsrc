$NetBSD: patch-Makefile.PL,v 1.2 2016/11/20 09:51:50 wiz Exp $

Build fix for curl-7.50.2.
https://rt.cpan.org/Public/Bug/Display.html?id=117793

--- Makefile.PL.orig	2014-02-21 16:08:09.000000000 +0000
+++ Makefile.PL
@@ -127,7 +127,7 @@ if (!defined($curl_h)) {
     close H;
 
     for my $e (sort @syms) {
-       if($e =~ /(OBSOLETE|^CURL_EXTERN|_LAST\z|_LASTENTRY\z)/) {
+       if($e =~ /(OBSOLETE|^CURL_EXTERN|^CURL_STRICTER\z||_LAST\z|_LASTENTRY\z)/) {
           next;
        }
        my ($group) = $e =~ m/^([^_]+_)/;
