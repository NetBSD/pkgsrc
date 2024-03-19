$NetBSD: patch-Makefile.PL,v 1.7 2024/03/19 14:08:24 schmonz Exp $

Avoid -regex, not available in OpenBSD find(1).
Set example SYSCONFDIR separately.

--- Makefile.PL.orig	2024-03-18 16:42:55.000000000 +0000
+++ Makefile.PL
@@ -20,6 +20,7 @@ SED?=sed
 # Additional configurable path variables.
 W3M_CGI_BIN?=$(PREFIX)/lib/w3m/cgi-bin
 SYSCONFDIR?=/etc/ikiwiki
+SYSCONFDIR_EXAMPLES?=$(PREFIX)/share/examples/ikiwiki
 MANDIR?=$(PREFIX)/share/man
 
 tflag=$(shell if [ -n "$$NOTAINT" ] && [ "$$NOTAINT" != 1 ]; then printf -- "-T"; fi)
@@ -140,11 +141,11 @@ underlay_install:
 extra_install: underlay_install
 	# Install example sites.
 	set -e; \
-	for dir in `$(FIND) doc/examples -type d ! -regex '.*discussion.*' | $(SED) -ne 's|^doc/examples/||p'`; do \
+	for dir in `$(FIND) doc/examples -type d ! -name discussion | $(SED) -ne 's|^doc/examples/||p'`; do \
 		install -d $(DESTDIR)$(PREFIX)/share/ikiwiki/examples/$$dir; \
 	done
 	set -e; \
-	for file in `$(FIND) doc/examples -type f ! -regex '.*discussion.*' | $(SED) -ne 's|^doc/examples/||p'`; do \
+	for file in `$(FIND) doc/examples -type f ! -name discussion.mdwn | $(SED) -ne 's|^doc/examples/||p'`; do \
 		if ! cp -pRL doc/examples/$$file $(DESTDIR)$(PREFIX)/share/ikiwiki/examples/$$file 2>/dev/null; then \
 			install -m 644 doc/examples/$$file $(DESTDIR)$(PREFIX)/share/ikiwiki/examples/$$file; \
 		fi; \
@@ -195,10 +196,10 @@ extra_install: underlay_install
 	
 	# These might fail if a regular user is installing into a home
 	# directory.
-	-install -d $(DESTDIR)$(SYSCONFDIR)
-	-install -m 0644 wikilist $(DESTDIR)$(SYSCONFDIR)
-	-install -m 0644 auto.setup $(DESTDIR)$(SYSCONFDIR)
-	-install -m 0644 auto-blog.setup $(DESTDIR)$(SYSCONFDIR)
+	-install -d $(DESTDIR)$(SYSCONFDIR_EXAMPLES)
+	-install -m 0644 wikilist $(DESTDIR)$(SYSCONFDIR_EXAMPLES)
+	-install -m 0644 auto.setup $(DESTDIR)$(SYSCONFDIR_EXAMPLES)
+	-install -m 0644 auto-blog.setup $(DESTDIR)$(SYSCONFDIR_EXAMPLES)
 
 # The git/hg plugins want to chdir; so does Devel::Cover. Skip those tests
 # to stop them hurting each other.
