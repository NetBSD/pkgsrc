$NetBSD: patch-src_keymap.h,v 1.1 2017/10/19 13:59:01 jperkin Exp $

From 180dcc578e13c6096e277fb853e7162db640f207 Mon Sep 17 00:00:00 2001
From: Alexandre Rostovtsev <tetromino@gentoo.org>
Date: Tue, 15 Nov 2011 03:06:40 -0500
Subject: [PATCH] Map both gdk's Meta and Alt to vte's Meta for >=gtk+-3.2.2
 compatibility

Also, since VTE_META_MASK is now a mask with multiple bits set, code that
compares gdk key modifiers to VTE_META_MASK by numerical equality is no
longer guaranteed to work. Therefore, for such comparisons a new function,
vte_keymap_fixup_modifiers, is introduced; it ensures that if any bits
matching matching VTE_META_MASK are set, then all are set.

https://bugzilla.gnome.org/show_bug.cgi?id=663779

--- src/keymap.h.orig	2011-06-07 17:01:32.000000000 +0000
+++ src/keymap.h
@@ -27,7 +27,7 @@
 
 G_BEGIN_DECLS
 
-#define VTE_META_MASK		GDK_META_MASK
+#define VTE_META_MASK		(GDK_META_MASK | GDK_MOD1_MASK)
 #define VTE_NUMLOCK_MASK	GDK_MOD2_MASK
 
 /* Map the specified keyval/modifier setup, dependent on the mode, to either
