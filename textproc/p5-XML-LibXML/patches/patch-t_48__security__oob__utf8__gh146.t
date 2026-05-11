$NetBSD: patch-t_48__security__oob__utf8__gh146.t,v 1.1 2026/05/11 17:39:13 wiz Exp $

fix: validate UTF-8 continuation bytes in domParseChar
https://github.com/cpan-authors/XML-LibXML/pull/149

--- t/48_security_oob_utf8_gh146.t.orig	2026-05-11 17:36:06.144804837 +0000
+++ t/48_security_oob_utf8_gh146.t
@@ -0,0 +1,110 @@
+# Security regression test for GitHub issue #146:
+# Out-of-bounds heap read in domParseChar on truncated UTF-8 sequences.
+#
+# domParseChar() read continuation bytes for multi-byte UTF-8 sequences
+# without verifying they exist or are valid. A truncated sequence (e.g.,
+# "a\xF0") caused reads past the NUL terminator into uninitialized heap
+# memory. This affects all DOM methods that validate node names via
+# LibXML_test_node_name(): createElement, createAttribute, setNodeName,
+# createElementNS, createAttributeNS, etc.
+#
+# Impact: denial of service (crash on unmapped memory) and potential
+# information disclosure (reading adjacent heap allocations).
+#
+# Before the fix, these inputs triggered undefined behavior — the
+# function read continuation bytes blindly, producing a garbage
+# codepoint and advancing the pointer past the buffer into heap memory.
+# After the fix, domParseChar rejects invalid/truncated sequences by
+# returning 0 with *len = 1, and the caller rejects the name.
+
+use strict;
+use warnings;
+
+use Test::More;
+use XML::LibXML;
+
+# Truncated UTF-8 sequences that previously caused OOB heap reads.
+# Each entry: [ bytes, description ]
+#
+# The leading "a" is a valid ASCII char so domParseChar succeeds on the
+# first character, then LibXML_test_node_name loops and hits the
+# truncated sequence on the second call — this is what triggered the
+# OOB read: len was set to 2/3/4 but the actual bytes weren't there.
+my @truncated_sequences = (
+    [ "a\xC0",             "truncated 2-byte (leader only)" ],
+    [ "a\xC2",             "truncated 2-byte (valid leader, missing continuation)" ],
+    [ "a\xE0",             "truncated 3-byte (leader only)" ],
+    [ "a\xE0\x80",         "truncated 3-byte (leader + 1 continuation)" ],
+    [ "a\xF0",             "truncated 4-byte (leader only)" ],
+    [ "a\xF0\x80",         "truncated 4-byte (leader + 1 continuation)" ],
+    [ "a\xF0\x80\x80",     "truncated 4-byte (leader + 2 continuations)" ],
+);
+
+# Invalid continuation bytes — the leader is valid but the continuations
+# are not 10xxxxxx. Before the fix, these were read without validation,
+# producing a garbage codepoint and advancing the pointer incorrectly.
+my @invalid_continuations = (
+    [ "a\xC2\x41",         "2-byte with ASCII continuation" ],
+    [ "a\xE0\x41\x80",     "3-byte with ASCII in first continuation" ],
+    [ "a\xE0\x80\x41",     "3-byte with ASCII in second continuation" ],
+    [ "a\xF0\x41\x80\x80", "4-byte with ASCII in first continuation" ],
+    [ "a\xF0\x80\x41\x80", "4-byte with ASCII in second continuation" ],
+    [ "a\xF0\x80\x80\x41", "4-byte with ASCII in third continuation" ],
+);
+
+my @all_bad = (@truncated_sequences, @invalid_continuations);
+
+# Methods that croak on invalid names
+# TEST:$bad_count=13
+# TEST:$croak_methods=3
+my @croak_methods = qw( createElement setNodeName createElementNS );
+
+# Methods that return undef on invalid names (no exception)
+# TEST:$undef_methods=2
+my @undef_methods = qw( createAttribute createAttributeNS );
+
+plan tests => scalar(@all_bad) * (scalar(@croak_methods) + scalar(@undef_methods));
+
+my $doc  = XML::LibXML::Document->new();
+my $nsURI = "http://example.com/ns";
+
+for my $case (@all_bad) {
+    my ($bytes, $desc) = @$case;
+
+    # Methods that die on bad names
+    for my $method (@croak_methods) {
+        my $died = 0;
+        eval {
+            if ($method eq 'createElement') {
+                $doc->createElement($bytes);
+            }
+            elsif ($method eq 'setNodeName') {
+                my $node = $doc->createElement("tmp");
+                $node->setNodeName($bytes);
+            }
+            elsif ($method eq 'createElementNS') {
+                $doc->createElementNS($nsURI, $bytes);
+            }
+        };
+        $died = 1 if $@;
+
+        # TEST*$bad_count*$croak_methods
+        ok($died, "$method dies on $desc");
+    }
+
+    # Methods that return undef on bad names
+    for my $method (@undef_methods) {
+        my $result;
+        eval {
+            if ($method eq 'createAttribute') {
+                $result = $doc->createAttribute($bytes, "value");
+            }
+            elsif ($method eq 'createAttributeNS') {
+                $result = $doc->createAttributeNS($nsURI, $bytes, "value");
+            }
+        };
+
+        # TEST*$bad_count*$undef_methods
+        ok(!defined $result, "$method returns undef on $desc");
+    }
+}
