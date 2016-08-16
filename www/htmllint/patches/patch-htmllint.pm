$NetBSD: patch-htmllint.pm,v 1.1 2016/08/16 00:11:35 maya Exp $

defined(%hash) was deprecated in perl and errors out

--- htmllint.pm.orig	2005-10-19 08:02:26.000000000 +0000
+++ htmllint.pm
@@ -4695,7 +4695,7 @@ sub WhineOmitEndTag
 
 sub Whine
 {
-  unless (defined(%messages)) { # デバグ用
+  unless (%messages) { # デバグ用
     print @_, "\n";
     return;
   }
@@ -5094,7 +5094,7 @@ sub ReadOptions
 
 sub ListWarnings(;\@)
 {
-  &ReadWarnings unless defined(%messages);
+  &ReadWarnings unless %messages;
   my $aref = shift;
   my %msgshort;
   foreach my $id (keys %shortid) { $msgshort{$shortid{$id}} = $id; }
