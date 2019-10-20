$NetBSD: patch-sample_test_TestRange.cs,v 1.1 2019/10/20 22:31:05 nia Exp $

Disambiguate Gtk.Range vs System.Range

https://github.com/mono/gtk-sharp/pull/263

--- sample/test/TestRange.cs.orig	2016-09-21 11:49:20.000000000 +0000
+++ sample/test/TestRange.cs
@@ -10,6 +10,8 @@ using System;
 
 using Gtk;
 
+using Range=Gtk.Range;
+
 namespace WidgetViewer {
 
 	public class TestRange
