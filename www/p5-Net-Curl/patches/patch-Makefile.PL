$NetBSD: patch-Makefile.PL,v 1.1 2023/03/13 07:26:33 wiz Exp $

Fix build with curl 7.87.0
https://github.com/sparky/perl-Net-Curl/issues/71#issuecomment-1465541787

--- Makefile.PL.orig	2020-03-08 11:58:49.000000000 +0000
+++ Makefile.PL
@@ -328,7 +328,7 @@ sub get_constants_headers
 
 	my @out;
 	foreach my $e (sort keys %syms) {
-		if ( $e =~ /(OBSOLETE|^CURL_EXTERN|_LAST\z|_LASTENTRY\z|^CURL_FORMAT_OFF_T$|^CURL_ISOCPP$|^CURLOPT$)/ ) {
+		if ( $e =~ /(OBSOLETE|^CURL_DEPRECATED\z|^CURL_EXTERN|^CURL_IGNORE_DEPRECATION\z|^CURLOPTDEPRECATED\z|_LAST\z|_LASTENTRY\z|^CURL_FORMAT_OFF_T$|^CURL_ISOCPP$|^CURLOPT$)/ ) {
 			next;
 		}
 		push @out, $e;
