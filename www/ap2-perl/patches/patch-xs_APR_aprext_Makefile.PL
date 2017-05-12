$NetBSD: patch-xs_APR_aprext_Makefile.PL,v 1.1 2017/05/12 08:42:54 manu Exp $

Avoid build failure because of a missing 'static' target

--- xs/APR/aprext/Makefile.PL.orig	2017-05-08 03:17:18.000000000 +0000
+++ xs/APR/aprext/Makefile.PL	2017-05-08 03:17:38.000000000 +0000
@@ -21,10 +21,10 @@
 
 push @obj, q{modperl_dummy.o};
 
 my @skip = qw(dynamic test);
-push @skip, q{static}
-    unless (Apache2::Build::BUILD_APREXT);
+#push @skip, q{static}
+#    unless (Apache2::Build::BUILD_APREXT);
 
 my %args = (NAME          => 'lib' . $build->{MP_APR_LIB},
             VERSION_FROM  => '../APR/APR.pm',
             SKIP          =>  [ @skip ] ,
