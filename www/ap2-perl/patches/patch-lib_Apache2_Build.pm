$NetBSD: patch-lib_Apache2_Build.pm,v 1.1 2016/08/04 14:18:15 nonaka Exp $

from mod_perl r1733566.

-----
Automatic compiler flags for gcc 5 and clang

To make compilation easier on gcc5/clang hosts, this patch automatically selects the appropriate c89 option, when modperl is being built with either gcc 5 or clang.

Tested by the author on Ubuntu 15.10 (with gcc 5.2.1), Fedora 23 (with gcc 5.3.1) and FreeBSD 10.2 (with clang).

Thanks to Klaus S. Madsen <ksm@jobindex.dk> for the patch.
-----

--- lib/Apache2/Build.pm.orig	2015-06-19 05:13:53.000000000 +0900
+++ lib/Apache2/Build.pm	2016-07-26 17:27:03.000000000 +0900
@@ -611,6 +611,14 @@ sub ap_ccopts {
         $ccopts .= " -DMP_TRACE";
     }
 
+    if ($self->has_gcc_version('5.0.0') && $ccopts !~ /-fgnu89-inline/) {
+        $ccopts .= " -fgnu89-inline";
+    }
+
+    if ($self->has_clang && $ccopts !~ /-std=gnu89/) {
+        $ccopts .= " -std=gnu89";
+    }
+
     # make sure apr.h can be safely included
     # for example Perl's included -D_GNU_SOURCE implies
     # -D_LARGEFILE64_SOURCE on linux, but this won't happen on
@@ -641,6 +649,16 @@ sub has_gcc_version {
     return cmp_tuples(\@tuples, \@r_tuples) == 1;
 }
 
+sub has_clang {
+    my $self = shift;
+
+    my $has_version = $self->perl_config('gccversion');
+
+    return 0 unless $has_version;
+
+    return $has_version =~ m/Clang/;
+}
+
 sub cmp_tuples {
     my ($num_a, $num_b) = @_;
 
