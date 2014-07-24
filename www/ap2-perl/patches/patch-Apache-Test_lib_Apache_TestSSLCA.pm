$NetBSD: patch-Apache-Test_lib_Apache_TestSSLCA.pm,v 1.1 2014/07/24 21:38:38 markd Exp $

Fix "Use of each() on hash after insertion without resetting hash iterator results in
undefined behavior" complaint from perl 5.20

--- Apache-Test/lib/Apache/TestSSLCA.pm.orig	2011-02-08 02:00:15.000000000 +0000
+++ Apache-Test/lib/Apache/TestSSLCA.pm
@@ -100,10 +100,10 @@ my $cert_dn = {
 };
 
 #generate DSA versions of the server certs/keys
-while (my($key, $val) = each %$cert_dn) {
+for my $key (keys %$cert_dn) {
     next unless $key =~ /^server/;
     my $name = join '_', $key, 'dsa';
-    $cert_dn->{$name} = { %$val }; #copy
+    $cert_dn->{$name} = { %{$cert_dn->{$key}} }; #copy
     $cert_dn->{$name}->{OU} =~ s/rsa/dsa/;
 }
 
