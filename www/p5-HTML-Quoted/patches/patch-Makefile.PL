$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 15:09:42 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2013-05-21 18:49:54.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 all_from    'lib/HTML/Quoted.pm';
 readme_from 'lib/HTML/Quoted.pm';
