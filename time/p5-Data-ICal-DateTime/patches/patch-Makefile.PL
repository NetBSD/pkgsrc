$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 18:07:50 mrg Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2017-06-07 11:01:05.185385995 -0700
+++ Makefile.PL	2017-06-07 11:00:51.936744561 -0700
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 name ('Data-ICal-DateTime');
