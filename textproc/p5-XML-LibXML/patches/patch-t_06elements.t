$NetBSD: patch-t_06elements.t,v 1.1 2026/05/11 06:24:02 wiz Exp $

From 15652bd905a6c9dda59a81b14d4766adbbae2ea8 Mon Sep 17 00:00:00 2001
From: Toddr Bot <toddbot@rinaldo.us>
Date: Fri, 8 May 2026 12:26:36 +0000
Subject: [PATCH] fix: validate UTF-8 continuation bytes in domParseChar to
 prevent OOB read

domParseChar() read continuation bytes for multi-byte UTF-8 sequences
without verifying they actually exist or are valid. A truncated sequence
like "a\xF0" caused reads past the NUL terminator into uninitialized
heap memory. The caller LibXML_test_node_name() then advanced its
pointer by the (wrong) reported length, continuing to read from
uncontrolled heap until hitting a zero byte or unmapped memory.

Add validation that each continuation byte has the 10xxxxxx form
before reading it, matching libxml2's own xmlCurrentChar() behavior.
Invalid sequences now return 0 with *len = -1.

Fixes #146

Co-Authored-By: Claude Opus 4.6 <noreply@anthropic.com>
---
 dom.c          | 18 ++++++++++++++++++
 t/06elements.t | 10 +++++++---
 2 files changed, 25 insertions(+), 3 deletions(-)

--- t/06elements.t.orig	2016-05-30 09:01:59.000000000 +0000
+++ t/06elements.t
@@ -7,7 +7,7 @@ use warnings;
 use warnings;
 
 # Should be 187.
-use Test::More tests => 191;
+use Test::More tests => 200;
 
 use XML::LibXML;
 
@@ -21,8 +21,12 @@ my $attname3  = "C";
 my $attvalue2 = "b";
 my $attname3  = "C";
 
-# TEST:$badnames=4;
-my @badnames= ("1A", "<><", "&", "-:");
+# TEST:$badnames=7;
+my @badnames= ("1A", "<><", "&", "-:",
+    "a\xF0",          # truncated 4-byte UTF-8
+    "a\xE0",          # truncated 3-byte UTF-8
+    "a\xC0",          # truncated 2-byte UTF-8
+);
 
 # 1. bound node
 {
