$NetBSD: patch-lib_CGI_FormBuilder.pm,v 1.1 2014/10/14 14:43:09 schmonz Exp $

Avoid unneeded warning from CGI.pm 4.05 or newer.

--- lib/CGI/FormBuilder.pm.orig	2007-03-02 18:13:14.000000000 +0000
+++ lib/CGI/FormBuilder.pm
@@ -855,7 +855,7 @@ sub keepextras {
 
     # Make sure to get all values
     for my $p (@keep) {
-        for my $v ($self->{params}->param($p)) {
+        for my $v (@{$self->{params}->param_fetch($p)}) {
             debug 1, "keepextras: saving hidden param $p = $v";
             push @html, htmltag('input', name => $p, type => 'hidden', value => $v);
         }
