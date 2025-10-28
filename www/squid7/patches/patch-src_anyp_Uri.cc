$NetBSD: patch-src_anyp_Uri.cc,v 1.1 2025/10/28 15:46:38 taca Exp $

Fix for Squid Bug 5520: Allow hostnames starting with decimal digit.

--- src/anyp/Uri.cc.orig	2025-10-15 20:31:05.000000000 +0000
+++ src/anyp/Uri.cc
@@ -637,23 +637,11 @@ AnyP::Uri::parseHost(Parser::Tokenizer &
 
     // no brackets implies we are looking at IPv4address or reg-name
 
-    static const CharacterSet IPv4chars = CharacterSet("period", ".") + CharacterSet::DIGIT;
-    SBuf ipv4ish; // IPv4address-ish
-    if (tok.prefix(ipv4ish, IPv4chars)) {
-        // This rejects non-IP addresses that our caller would have
-        // otherwise mistaken for a domain name (e.g., '127.0.0' or '1234.5').
-        Ip::Address ipCheck;
-        if (!ipCheck.fromHost(ipv4ish.c_str()))
-            throw TextException("malformed IP address in uri-host", Here());
-
-        return ipv4ish;
-    }
-
-    // XXX: This code does not detect/reject some bad host values (e.g. "!#$%&").
+    // XXX: This code does not detect/reject some bad host values (e.g. `!#$%&`).
     // TODO: Add more checks here, after migrating the
     // non-CONNECT uri-host parsing code to use us.
 
-    SBuf otherHost; // IPv4address-ish or reg-name-ish;
+    SBuf otherHost; // IPv4address-ish or reg-name-ish
     // ":" is not in TCHAR so we will stop before any port specification
     if (tok.prefix(otherHost, CharacterSet::TCHAR))
         return otherHost;
