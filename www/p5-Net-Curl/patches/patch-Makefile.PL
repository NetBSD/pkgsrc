$NetBSD: patch-Makefile.PL,v 1.5 2025/07/24 13:41:04 wiz Exp $

Fix build with curl 8.13.0.
https://github.com/sparky/perl-Net-Curl/issues/83

--- Makefile.PL.orig	2025-01-20 14:34:15.000000000 +0000
+++ Makefile.PL
@@ -341,7 +341,7 @@ sub get_constants_headers
 
 	my @out;
 	foreach my $e (sort keys %syms) {
-		if ( $e =~ /(OBSOLETE|^CURL_DEPRECATED\z|^CURL_EXTERN|^CURL_IGNORE_DEPRECATION\z|^CURLOPTDEPRECATED\z|_LAST\z|_LASTENTRY\z|^CURL_FORMAT_OFF_T$|^CURL_ISOCPP$|^CURLOPT$)/ ) {
+		if ( $e =~ /(OBSOLETE|^CURL_DEPRECATED\z|^CURL_EXTERN|^CURL_IGNORE_DEPRECATION\z|^CURLOPTDEPRECATED\z|_LAST\z|_LASTENTRY\z|^CURL_FORMAT_OFF_T$|^CURL_ISOCPP$|^CURLOPT$|^CURL_HAS_DECLSPEC_ATTRIBUTE\z)/ ) {
 			next;
 		}
 		push @out, $e;
