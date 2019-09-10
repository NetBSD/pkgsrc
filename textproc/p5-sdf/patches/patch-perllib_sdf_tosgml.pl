$NetBSD: patch-perllib_sdf_tosgml.pl,v 1.1 2019/09/10 21:20:35 schmonz Exp $

Use /m instead of $*, no longer available in Perl 5.30.
Patch from Debian: 005_multiline.diff

--- perllib/sdf/tosgml.pl.orig	1998-10-23 22:59:43.000000000 +0000
+++ perllib/sdf/tosgml.pl
@@ -415,11 +415,6 @@ sub _SgmlFinalise {
 sub _SgmlEscape {
     local($text) = @_;
 #   local($result);
-    local($old_match_flag);
-
-    # Enable multi-line matching
-    $old_match_flag = $*;
-    $* = 1;
 
     # Escape the special symbols. Note that it isn't exactly clear
     # from the SGML-Tools and/or QWERTZ DTD documentation as to
@@ -437,9 +432,6 @@ sub _SgmlEscape {
     $text =~ s/\|/&verbar;/g;
     $text =~ s/\[/&ftag;/g;
 
-    # Reset multi-line matching flag
-    $* = $old_match_flag;
-
     # Return result
     $text;
 }
@@ -527,15 +519,10 @@ sub _SgmlAddAnchors {
     local($result);
     local($value);
     local($user_ext);
-    local($old_match_flag);
 
     # Skip this routine for now
     return 0;
 
-    # Enable multi-line matching
-    $old_match_flag = $*;
-    $* = 1;
-
     # For hypertext jumps, surround the text. If the
     # text contains a jump, the existing jump is removed.
     if ($attr{'jump'} ne '') {
@@ -571,9 +558,6 @@ sub _SgmlAddAnchors {
         $result++;
     }
 
-    # Reset multi-line matching flag
-    $* = $old_match_flag;
-
     # Return result
     return $result;
 }
