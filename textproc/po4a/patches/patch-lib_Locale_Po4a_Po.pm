$NetBSD: patch-lib_Locale_Po4a_Po.pm,v 1.3 2024/01/29 16:08:20 adam Exp $

Use a sufficiently capable diff.
Write to the full physical null device.

--- lib/Locale/Po4a/Po.pm.orig	2024-01-28 23:39:44.000000000 +0000
+++ lib/Locale/Po4a/Po.pm
@@ -329,7 +329,7 @@ sub read {
     $self->{lang} = $lang;
 
     if ($checkvalidity) {   # We sometimes need to read a file even if it may be invalid (eg to test whether it's empty)
-        my $cmd = "msgfmt" . $Config{_exe} . " --check-format --check-domain -o /dev/null \"" . $filename . '"';
+        my $cmd = "@PREFIX@/bin/msgfmt" . $Config{_exe} . " --check-format --check-domain -o /dev/null \"" . $filename . '"';
 
         my $locale = $ENV{'LC_ALL'};
         $ENV{'LC_ALL'} = "C";
@@ -634,7 +634,7 @@ sub move_po_if_needed {
     my $diff;
 
     if ( -e $old_po ) {
-        $diff = qx(diff -q -I'^#:' -I'^\"POT-Creation-Date:' -I'^\"PO-Revision-Date:' $old_po $new_po);
+        $diff = qx(@DIFF@ -q -I'^#:' -I'^\"POT-Creation-Date:' -I'^\"PO-Revision-Date:' $old_po $new_po);
         if ( $diff eq "" ) {
             unlink $new_po
               or die wrap_msg( dgettext( "po4a", "Cannot unlink %s: %s." ), $new_po, $! );
