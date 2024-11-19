$NetBSD: patch-Makefile.PL,v 1.3 2024/11/19 07:08:47 wiz Exp $

Fix build with newer curls.
https://github.com/sparky/perl-Net-Curl/issues/78

--- Makefile.PL.orig	2024-11-19 06:39:18.392593627 +0000
+++ Makefile.PL
@@ -328,7 +328,7 @@ sub get_constants_headers
 		while(<H>) {
 			# Skip defines without values like:
 			#	#define CURL_STRICTER
-			if (m{^#\s*define\s+(CURL\w*)\s*$}) {
+			if (m{^#\s*define\s+(CURL\w*)\s*(/\*.*\*/)?$}) {
 				chomp;
 				warn "Skipping '$_': does not define a symbol";
 				next;
