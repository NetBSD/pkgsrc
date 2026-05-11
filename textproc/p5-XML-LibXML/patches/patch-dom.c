$NetBSD: patch-dom.c,v 1.1 2026/05/11 06:24:02 wiz Exp $

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

--- dom.c.orig	2017-10-23 08:52:55.000000000 +0000
+++ dom.c
@@ -292,6 +292,13 @@ domParseChar( xmlChar *cur, int *len )
         if ((c & 0xe0) == 0xe0) {
             if ((c & 0xf0) == 0xf0) {
                 /* 4-byte code */
+                if ((cur[1] & 0xC0) != 0x80 ||
+                    (cur[2] & 0xC0) != 0x80 ||
+                    (cur[3] & 0xC0) != 0x80)
+                {
+                    *len = -1;
+                    return(0);
+                }
                 *len = 4;
                 val = (cur[0] & 0x7) << 18;
                 val |= (cur[1] & 0x3f) << 12;
@@ -299,6 +306,12 @@ domParseChar( xmlChar *cur, int *len )
                 val |= cur[3] & 0x3f;
             } else {
                 /* 3-byte code */
+                if ((cur[1] & 0xC0) != 0x80 ||
+                    (cur[2] & 0xC0) != 0x80)
+                {
+                    *len = -1;
+                    return(0);
+                }
                 *len = 3;
                 val = (cur[0] & 0xf) << 12;
                 val |= (cur[1] & 0x3f) << 6;
@@ -306,6 +319,11 @@ domParseChar( xmlChar *cur, int *len )
             }
             } else {
             /* 2-byte code */
+            if ((cur[1] & 0xC0) != 0x80)
+            {
+                *len = -1;
+                return(0);
+            }
             *len = 2;
             val = (cur[0] & 0x1f) << 6;
             val |= cur[1] & 0x3f;
