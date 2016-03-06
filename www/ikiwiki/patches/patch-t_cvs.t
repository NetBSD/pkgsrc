$NetBSD: patch-t_cvs.t,v 1.1 2016/03/06 19:30:06 schmonz Exp $

From upstream git (b422295): Fix CVS tests by uninverting $installed.

--- t/cvs.t.orig	2016-01-21 09:53:28.000000000 +0000
+++ t/cvs.t
@@ -609,10 +609,10 @@ sub _generate_and_configure_post_commit_
 
 	require IkiWiki::Wrapper;
 	if ($installed) {
-		$IkiWiki::program_to_wrap = 'ikiwiki.out';
+		$IkiWiki::program_to_wrap = `which ikiwiki`;
 	}
 	else {
-		$IkiWiki::program_to_wrap = `which ikiwiki`;
+		$IkiWiki::program_to_wrap = './ikiwiki.out';
 	}
 	# XXX substitute its interpreter to Makefile's $(PERL)
 	# XXX best solution: do this to all scripts during build
