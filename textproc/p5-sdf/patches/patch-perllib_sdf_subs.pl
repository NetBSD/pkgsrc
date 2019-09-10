$NetBSD: patch-perllib_sdf_subs.pl,v 1.1 2019/09/10 21:20:35 schmonz Exp $

Use /m instead of $*, no longer available in Perl 5.30.
Patch from Debian: 005_multiline.diff

--- perllib/sdf/subs.pl.orig	1998-10-26 08:24:46.000000000 +0000
+++ perllib/sdf/subs.pl
@@ -620,10 +620,6 @@ sub ExecEventsStyleMask {
     local($event, $action, $mask);
     local($old_match_rule);
 
-    # Ensure multi-line matching is enabled
-    $old_match_rule = $*;
-    $* = 1;
-
     for ($event = $#code; $event >= 0; $event--) {
 
         # get the action to execute, if any
@@ -632,7 +628,7 @@ sub ExecEventsStyleMask {
 
         # Mask out events
         $mask = $mask[$event];
-        next if $mask ne '' && $style !~ /^$mask$/;
+        next if $mask ne '' && $style !~ /^$mask$/m;
         return if $attr{'noevents'};
 
         # execute the action
@@ -640,8 +636,6 @@ sub ExecEventsStyleMask {
         &'AppMsg("warning", "execution of '$action' failed: $@") if $@;
     }
 
-    # Restore the multi-line match flag setting
-    $* = $old_match_rule;
 }
 
 #
@@ -654,11 +648,6 @@ sub ExecEventsNameMask {
     local(*code, *mask) = @_;
 #   local();
     local($event, $action, $mask);
-    local($old_match_rule);
-
-    # Ensure multi-line matching is enabled
-    $old_match_rule = $*;
-    $* = 1;
 
     for ($event = $#code; $event >= 0; $event--) {
 
@@ -668,15 +657,12 @@ sub ExecEventsNameMask {
 
         # Mask out events
         $mask = $mask[$event];
-        next if $mask ne '' && $name !~ /^$mask$/;
+        next if $mask ne '' && $name !~ /^$mask$/m;
 
         # execute the action
         eval $action;
         &'AppMsg("warning", "execution of '$action' failed: $@") if $@;
     }
-
-    # Restore the multi-line match flag setting
-    $* = $old_match_rule;
 }
 #
 # >>Description::
