$NetBSD: patch-perllib_sdf_tohtml.pl,v 1.1 2019/09/10 21:20:35 schmonz Exp $

Use /m instead of $*, no longer available in Perl 5.30.
Patch from Debian: 005_multiline.diff

--- perllib/sdf/tohtml.pl.orig	1998-10-23 22:59:44.000000000 +0000
+++ perllib/sdf/tohtml.pl
@@ -759,19 +759,12 @@ sub _HtmlEscape {
 #   local($result);
     local($old_match_flag);
 
-    # Enable multi-line matching
-    $old_match_flag = $*;
-    $* = 1;
-
     # Escape the symbols
     $text =~ s/\&/&amp;/g;
     $text =~ s/\</&lt;/g;
     $text =~ s/\>/&gt;/g;
     $text =~ s/\"/&quot;/g;
 
-    # Reset multi-line matching flag
-    $* = $old_match_flag;
-
     # Return result
     $text;
 }
@@ -865,10 +858,6 @@ sub _HtmlAddAnchors {
     local($user_ext);
     local($old_match_flag);
 
-    # Enable multi-line matching
-    $old_match_flag = $*;
-    $* = 1;
-
     # For hypertext jumps, surround the text. If the
     # text contains a jump, the existing jump is removed.
     if ($attr{'jump'} ne '') {
@@ -904,9 +893,6 @@ sub _HtmlAddAnchors {
         $result++;
     }
 
-    # Reset multi-line matching flag
-    $* = $old_match_flag;
-
     # Return result
     return $result;
 }
