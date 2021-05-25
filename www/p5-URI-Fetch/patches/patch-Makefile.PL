$NetBSD: patch-Makefile.PL,v 1.1 2021/05/25 11:20:55 schmonz Exp $

ExtUtils-MakeMaker-7.48 rejects invalid MIN_PERL_VERSION values.
Apply patch from <https://rt.cpan.org/Public/Bug/Display.html?id=133491>.

--- Makefile.PL.orig	2016-07-02 08:35:41.000000000 +0000
+++ Makefile.PL
@@ -2,7 +2,7 @@
 use strict;
 use warnings;
 
-use 5.008_001;
+use 5.008001;
 
 use ExtUtils::MakeMaker;
 
@@ -15,7 +15,7 @@ my %WriteMakefileArgs = (
   "DISTNAME" => "URI-Fetch",
   "EXE_FILES" => [],
   "LICENSE" => "perl",
-  "MIN_PERL_VERSION" => "5.008_001",
+  "MIN_PERL_VERSION" => "5.008001",
   "NAME" => "URI::Fetch",
   "PREREQ_PM" => {
     "Carp" => 0,
