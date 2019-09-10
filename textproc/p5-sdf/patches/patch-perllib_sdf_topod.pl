$NetBSD: patch-perllib_sdf_topod.pl,v 1.1 2019/09/10 21:20:35 schmonz Exp $

Use /m instead of $*, no longer available in Perl 5.30.
Patch from Debian: 005_multiline.diff

--- perllib/sdf/topod.pl.orig	1998-10-23 22:59:43.000000000 +0000
+++ perllib/sdf/topod.pl
@@ -388,19 +388,11 @@ sub _PodFinalise {
 sub _PodEscape {
     local($text, $nested) = @_;
 #   local($result);
-    local($old_match_flag);
-
-    # Enable multi-line matching
-    $old_match_flag = $*;
-    $* = 1;
 
     # Escape the symbols
     my $gt = $nested ? 'E<gt>' : '>';
     $text =~ s/([A-Z])\<|\>/length($&) == 1 ? $gt : "$1E<lt>"/eg;
 
-    # Reset multi-line matching flag
-    $* = $old_match_flag;
-
     # Return result
     $text;
 }
