$NetBSD: patch-IkiWiki_Plugin_git.pm,v 1.1 2013/01/15 23:10:57 schmonz Exp $

commit 12c9219d671c672fedcf9e9ab7f9187b23b8f7f4
Author: Shlomi Fish <shlomif@shlomifish.org>
Date:   Mon Dec 17 22:44:54 2012 +0200

    Fix some warnigns in recent perls.
    
    All existing tests pass.

--- IkiWiki/Plugin/git.pm.orig	2012-08-25 15:12:13.000000000 +0000
+++ IkiWiki/Plugin/git.pm
@@ -341,8 +341,8 @@ sub parse_diff_tree ($) {
 	my $dt_ref = shift;
 
 	# End of stream?
-	return if !defined @{ $dt_ref } ||
-		  !defined @{ $dt_ref }[0] || !length @{ $dt_ref }[0];
+	return if ! @{ $dt_ref } ||
+		  !defined $dt_ref->[0] || !length $dt_ref->[0];
 
 	my %ci;
 	# Header line.
