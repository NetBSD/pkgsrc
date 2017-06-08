$NetBSD: patch-Makefile.PL,v 1.1 2017/06/08 12:58:33 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2013-02-04 23:47:40.000000000 +0000
+++ Makefile.PL
@@ -25,6 +25,8 @@ use warnings;
 # use only standard modules here!  any non-standard module, or anything which is
 # a dependency which may not be installed, should be use'd from the dependency
 # test eval, below.
+use FindBin;
+use lib $FindBin::Bin;
 use ExtUtils::MakeMaker;
 use File::Spec;
 use Cwd;
