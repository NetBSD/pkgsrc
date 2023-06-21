$NetBSD: patch-lib_Locale_Po4a_Po.pm,v 1.2 2023/06/21 19:08:06 schmonz Exp $

Use a sufficiently capable diff.
Write to the full physical null device.

--- lib/Locale/Po4a/Po.pm.orig	2023-01-01 00:30:43.000000000 +0000
+++ lib/Locale/Po4a/Po.pm
@@ -325,7 +325,7 @@ sub read {
     $lang =~ s/\.po$//;
     $self->{lang} = $lang;
 
-    my $cmd = "msgfmt" . $Config{_exe} . " --check-format --check-domain -o /dev/null " . $filename;
+    my $cmd = "@PREFIX@/bin/msgfmt" . $Config{_exe} . " --check-format --check-domain -o @PO4A_DEVNULL@ " . $filename;
 
     my $locale = $ENV{'LC_ALL'};
     $ENV{'LC_ALL'} = "C";
@@ -621,7 +621,7 @@ sub move_po_if_needed {
     my $diff;
 
     if ( -e $old_po ) {
-        $diff = qx(diff -q -I'^#:' -I'^\"POT-Creation-Date:' -I'^\"PO-Revision-Date:' $old_po $new_po);
+        $diff = qx(@DIFF@ -q -I'^#:' -I'^\"POT-Creation-Date:' -I'^\"PO-Revision-Date:' $old_po $new_po);
         if ( $diff eq "" ) {
             unlink $new_po
               or die wrap_msg( dgettext( "po4a", "Cannot unlink %s: %s." ), $new_po, $! );
