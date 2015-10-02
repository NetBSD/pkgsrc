$NetBSD: patch-StripScripts.pm,v 1.1.2.2 2015/10/02 19:46:29 bsiegert Exp $

Bug/typo now cause a fatal error in perl 5.22
From https://rt.cpan.org/Public/Bug/Display.html?id=98110

--- StripScripts.pm.orig	2015-09-25 21:55:08.000000000 +0200
+++ StripScripts.pm	2015-09-25 22:03:01.000000000 +0200
@@ -1630,7 +1630,7 @@
 
 sub _hss_attval_size {
     $_[3]
-        =~ /^\s*([+-]?\d{1,20}(?:\.\d{1,20)?)\s*((?:\%|\*|ex|px|pc|cm|mm|in|pt|em)?)\s*$/i
+	=~ /^\s*([+-]?\d{1,20}(?:\.\d{1,20})?)\s*((?:\%|\*|ex|px|pc|cm|mm|in|pt|em)?)\s*$/i 
         ? lc "$1$2"
         : undef;
 }
