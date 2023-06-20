$NetBSD: patch-lib_Locale_Po4a_Po.pm,v 1.1 2023/06/20 15:30:12 schmonz Exp $

Use a sufficiently capable diff.

--- lib/Locale/Po4a/Po.pm.orig	2023-01-01 00:30:43.000000000 +0000
+++ lib/Locale/Po4a/Po.pm
@@ -621,7 +621,7 @@ sub move_po_if_needed {
     my $diff;
 
     if ( -e $old_po ) {
-        $diff = qx(diff -q -I'^#:' -I'^\"POT-Creation-Date:' -I'^\"PO-Revision-Date:' $old_po $new_po);
+        $diff = qx(@DIFF@ -q -I'^#:' -I'^\"POT-Creation-Date:' -I'^\"PO-Revision-Date:' $old_po $new_po);
         if ( $diff eq "" ) {
             unlink $new_po
               or die wrap_msg( dgettext( "po4a", "Cannot unlink %s: %s." ), $new_po, $! );
