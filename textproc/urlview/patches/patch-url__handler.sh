$NetBSD: patch-url__handler.sh,v 1.1 2015/02/19 18:47:17 snj Exp $

--- url_handler.sh.orig	2000-07-04 03:14:30.000000000 -0700
+++ url_handler.sh	2015-02-19 01:01:08.000000000 -0800
@@ -1,4 +1,4 @@
-#! /bin/bash
+#!/bin/sh
 
 #   Copyright (c) 1998  Martin Schulze <joey@debian.org>
 #   Slightly modified by Luis Francisco Gonzalez <luisgh@debian.org>
@@ -42,7 +42,7 @@ XTERM=/usr/X11R6/bin/xterm
 ###########################################################################
 # Change bellow this at your own risk
 ###########################################################################
-function getprg()
+getprg()
 {
     local ele tag prog
 
