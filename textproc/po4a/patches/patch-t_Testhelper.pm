$NetBSD: patch-t_Testhelper.pm,v 1.1 2024/02/09 12:18:08 jperkin Exp $

Use portable chmod arguments.

--- t/Testhelper.pm.orig	2024-02-09 12:09:14.811542170 +0000
+++ t/Testhelper.pm
@@ -212,8 +212,8 @@ sub run_one_po4aconf {
         push @setup,    "chmod -r-w-x " . $closed_path;    # Don't even look at the closed path
         push @teardown, "chmod +r+w+x " . $closed_path;    # Restore permissions
         push @setup,    "chmod +r+x    $path";             # Look into the path of this test
-        push @setup,    "chmod -w   -R $path";             # But don't change any file in there
-        push @teardown, "chmod +w   -R $path";             # Restore permissions
+        push @setup,    "chmod -R -w   $path";             # But don't change any file in there
+        push @teardown, "chmod -R +w   $path";             # Restore permissions
     }
 
     my $cwd     = cwd();
@@ -234,7 +234,7 @@ sub run_one_po4aconf {
     } elsif ( $mode eq 'curdir' ) {
         $tmppath .= '-cur';
         push @setup, "cp -r $path/* $tmppath";
-        push @setup, "chmod +w -R $tmppath" unless $^O eq 'MSWin32';
+        push @setup, "chmod -R +w $tmppath" unless $^O eq 'MSWin32';
         $run_from = $tmppath;
     } else {
         die "Malformed test: mode $mode unknown\n";
