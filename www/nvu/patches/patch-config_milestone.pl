$NetBSD: patch-config_milestone.pl,v 1.1 2015/06/25 07:39:26 joerg Exp $

--- config/milestone.pl.orig	2015-06-24 20:47:42.000000000 +0000
+++ config/milestone.pl
@@ -85,7 +85,7 @@ $MILESTONE_FILE  = "$TOPSRCDIR/config/mi
 #
 my $milestone = Moz::Milestone::getOfficialMilestone($MILESTONE_FILE);
 
-if (defined(@TEMPLATE_FILE)) {
+if (@TEMPLATE_FILE) {
   my $TFILE;
 
   foreach $TFILE (@TEMPLATE_FILE) {
