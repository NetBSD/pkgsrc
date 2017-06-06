$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 15:03:01 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2012-06-14 10:08:39.000000000 +0000
+++ Makefile.PL
@@ -1,4 +1,6 @@
 BEGIN {
+	use FindBin;
+	use lib $FindBin::Bin;
 	use inc::Module::Install;
 
 	my @mip = qw(
