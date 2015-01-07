$NetBSD: patch-IkiWiki_Plugin_comments.pm,v 1.1 2015/01/07 16:09:23 schmonz Exp $

For anonymous-style comments committed directly via the VCS (i.e.,
imported from another CMS), link to the provided URL if any.

--- IkiWiki/Plugin/comments.pm.orig	2015-01-03 23:25:58.000000000 +0000
+++ IkiWiki/Plugin/comments.pm
@@ -223,22 +223,9 @@ sub preprocess {
 		$commentauthor = gettext("Anonymous");
 	}
 
-	$commentstate{$page}{commentuser} = $commentuser;
-	$commentstate{$page}{commentopenid} = $commentopenid;
-	$commentstate{$page}{commentip} = $commentip;
-	$commentstate{$page}{commentauthor} = $commentauthor;
-	$commentstate{$page}{commentauthorurl} = $commentauthorurl;
-	$commentstate{$page}{commentauthoravatar} = $params{avatar};
-	if (! defined $pagestate{$page}{meta}{author}) {
-		$pagestate{$page}{meta}{author} = $commentauthor;
-	}
-	if (! defined $pagestate{$page}{meta}{authorurl}) {
-		$pagestate{$page}{meta}{authorurl} = $commentauthorurl;
-	}
-
 	if ($config{comments_allowauthor}) {
 		if (defined $params{claimedauthor}) {
-			$pagestate{$page}{meta}{author} = $params{claimedauthor};
+			$commentauthor = $params{claimedauthor};
 		}
 
 		if (defined $params{url}) {
@@ -250,12 +237,21 @@ sub preprocess {
 			}
 
 			if (safeurl($url)) {
-				$pagestate{$page}{meta}{authorurl} = $url;
+				$commentauthorurl = $url;
 			}
 		}
 	}
-	else {
+
+	$commentstate{$page}{commentuser} = $commentuser;
+	$commentstate{$page}{commentopenid} = $commentopenid;
+	$commentstate{$page}{commentip} = $commentip;
+	$commentstate{$page}{commentauthor} = $commentauthor;
+	$commentstate{$page}{commentauthorurl} = $commentauthorurl;
+	$commentstate{$page}{commentauthoravatar} = $params{avatar};
+	if (! defined $pagestate{$page}{meta}{author}) {
 		$pagestate{$page}{meta}{author} = $commentauthor;
+	}
+	if (! defined $pagestate{$page}{meta}{authorurl}) {
 		$pagestate{$page}{meta}{authorurl} = $commentauthorurl;
 	}
 
