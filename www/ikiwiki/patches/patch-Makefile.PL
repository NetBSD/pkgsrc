$NetBSD: patch-Makefile.PL,v 1.5 2019/08/31 20:19:23 schmonz Exp $

Avoid -regex, not available in OpenBSD find(1).

--- Makefile.PL.orig	2019-02-26 23:01:54.000000000 +0000
+++ Makefile.PL
@@ -140,11 +140,11 @@ underlay_install:
 extra_install: underlay_install
 	# Install example sites.
 	set -e; \
-	for dir in `$(FIND) doc/examples -type d ! -regex '.*discussion.*' | $(SED) -e 's|^doc/examples/||'`; do \
+	for dir in `$(FIND) doc/examples -type d ! -name discussion | $(SED) -e 's|^doc/examples/||'`; do \
 		install -d $(DESTDIR)$(PREFIX)/share/ikiwiki/examples/$$dir; \
 	done
 	set -e; \
-	for file in `$(FIND) doc/examples -type f ! -regex '.*discussion.*' | $(SED) -e 's|^doc/examples/||'`; do \
+	for file in `$(FIND) doc/examples -type f ! -name discussion.mdwn | $(SED) -e 's|^doc/examples/||'`; do \
 		if ! cp -pRL doc/examples/$$file $(DESTDIR)$(PREFIX)/share/ikiwiki/examples/$$file 2>/dev/null; then \
 			install -m 644 doc/examples/$$file $(DESTDIR)$(PREFIX)/share/ikiwiki/examples/$$file; \
 		fi; \
