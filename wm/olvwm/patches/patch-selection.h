$NetBSD: patch-selection.h,v 1.1 2013/03/28 21:40:11 joerg Exp $

--- selection.h.orig	2013-03-28 19:20:53.000000000 +0000
+++ selection.h
@@ -17,7 +17,6 @@
 extern	Time	SelectionTime;
 
 extern	Bool	IsSelected(/*  client  */);
-extern	int	AddSelection(/*  client, time  */);
 extern	Bool	RemoveSelection(/*  client  */);
 extern	Bool	ToggleSelection(/*  client, time  */);
 extern	void	ClearSelections(/*  dpy  */);
