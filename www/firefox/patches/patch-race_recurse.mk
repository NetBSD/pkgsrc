$NetBSD: patch-race_recurse.mk,v 1.1.2.2 2020/10/29 12:18:54 spz Exp $

Apply patch from Firefox 83 to fix a rare build race.

# HG changeset patch
# User Mike Hommey <mh+mozilla@glandium.org>
# Date 1602073076 0
# Node ID 4489f33bf6521cdc4ecc915063d8733f5daa0814
# Parent  569eb3fda698916ef2dc1c844a76ccd8642e0ef6
Bug 1669442 - Fix dependency between libxul and mozgtk after bug 1573566. r=andi,dmajor

Bug 1573566 moved libxul from toolkit/library to toolkit/library/build,
and that should be reflected in config/recurse.mk.

It's amazing the race condition hasn't caused problems earlier than now.

Differential Revision: https://phabricator.services.mozilla.com/D92708


--- config/recurse.mk.orig	2020-10-14 17:20:16.000000000 +0000
+++ config/recurse.mk
@@ -206,7 +206,7 @@ endif
 # Interdependencies that moz.build world don't know about yet for compilation.
 # Note some others are hardcoded or "guessed" in recursivemake.py and emitter.py
 ifeq ($(MOZ_WIDGET_TOOLKIT),gtk)
-toolkit/library/target: widget/gtk/mozgtk/gtk3/target
+toolkit/library/build/target: widget/gtk/mozgtk/gtk3/target
 endif
 
 ifndef MOZ_FOLD_LIBS
