$NetBSD: patch-Makefile.PL,v 1.1.1.1 2012/04/15 01:50:08 obache Exp $

* registration is prepared by pkgsrc INSTALL/DEINSTALL script

--- Makefile.PL.orig	2007-07-02 07:59:45.000000000 +0000
+++ Makefile.PL
@@ -103,7 +103,7 @@ WriteMakefile(
 sub MY::install {
     package MY;
     my $script = shift->SUPER::install(@_);
-    if (ExtUtils::MakeMaker::prompt("Do you want to alter ParserDetails.ini?", "Y") =~ /^y/i) {
+    if (ExtUtils::MakeMaker::prompt("Do you want to alter ParserDetails.ini?", "N") =~ /^y/i) {
         $script =~ s/install :: (.*)$/install :: $1 install_expat_xs/m;
         $script .= <<"INSTALL";
 
