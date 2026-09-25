$NetBSD: patch-libhttpd.c,v 1.1 2026/09/25 14:20:40 wiz Exp $

Not a security fix, and not an underflow.  The stock code

	i = strlen( hc->origfilename ) - strlen( hc->pathinfo );
	if ( i > 0 && strcmp( &hc->origfilename[i], hc->pathinfo ) == 0 )
	    hc->origfilename[i - 1] = '\0';

already prevents the index from going negative: the "i > 0" test means
origfilename[i-1] is only reached with i >= 1.  I checked this after
mistaking it for the same shape as the underflows in
patch-CVE-2007-0158; it is not one.

What it does change is behaviour.  When PATH_INFO is the whole of
origfilename (i == 0) the stock code leaves origfilename alone, so the
pathinfo part is not removed from it as the comment above it says it
should be.  This makes that case set origfilename to the empty string.
FreeBSD ports and Debian both carry the same change; Debian files it
under "path-info" rather than as a security patch, which is the right
reading.

Included because the neighbouring CVE patches touch the same file and a
reader will otherwise wonder why this one spot is left as it is.  Drop
this patch if the behaviour change is not wanted -- the CVE patches do
not depend on it.

--- libhttpd.c.orig
+++ libhttpd.c
@@ -2351,8 +2351,13 @@
 	{
 	int i;
 	i = strlen( hc->origfilename ) - strlen( hc->pathinfo );
-	if ( i > 0 && strcmp( &hc->origfilename[i], hc->pathinfo ) == 0 )
-	    hc->origfilename[i - 1] = '\0';
+	if ( i >= 0 && strcmp( &hc->origfilename[i], hc->pathinfo ) == 0 )
+	    {
+	    if ( i == 0 )
+		hc->origfilename[0] = '\0';
+	    else
+		hc->origfilename[i - 1] = '\0';
+	    }
 	}
 
     /* If the expanded filename is an absolute path, check that it's still
