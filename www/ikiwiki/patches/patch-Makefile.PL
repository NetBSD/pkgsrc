$NetBSD: patch-Makefile.PL,v 1.3 2018/03/02 19:22:24 schmonz Exp $

Avoid unexpected full paths from find(1).

--- Makefile.PL.orig	2018-02-28 10:41:06.000000000 +0000
+++ Makefile.PL
@@ -96,7 +96,7 @@ myclean: clean
 underlay_install:
 	install -d $(DESTDIR)$(PREFIX)/share/ikiwiki
 	set -e; \
-	for dir in `cd underlays && $(FIND) . -follow -type d`; do \
+	for dir in `$(FIND) underlays -follow -mindepth 1 -type d | $(SED) -e 's|^underlays/||'`; do \
 		install -d $(DESTDIR)$(PREFIX)/share/ikiwiki/$$dir; \
 		for file in `$(FIND) underlays/$$dir -follow -maxdepth 1 -type f ! -name jquery.js ! -name jquery-ui.css ! -name jquery-ui.js ! -name jquery.tmpl.js`; do \
 			if ! cp -pRL $$file $(DESTDIR)$(PREFIX)/share/ikiwiki/$$dir 2>/dev/null; then \
@@ -137,11 +137,11 @@ underlay_install:
 extra_install: underlay_install
 	# Install example sites.
 	set -e; \
-	for dir in `cd doc/examples; $(FIND) . -type d ! -regex '.*discussion.*'`; do \
+	for dir in `$(FIND) doc/examples -type d ! -regex '.*discussion.*' | $(SED) -e 's|^doc/examples/||'`; do \
 		install -d $(DESTDIR)$(PREFIX)/share/ikiwiki/examples/$$dir; \
 	done
 	set -e; \
-	for file in `cd doc/examples; $(FIND) . -type f ! -regex '.*discussion.*'`; do \
+	for file in `$(FIND) doc/examples -type f ! -regex '.*discussion.*' | $(SED) -e 's|^doc/examples/||'`; do \
 		if ! cp -pRL doc/examples/$$file $(DESTDIR)$(PREFIX)/share/ikiwiki/examples/$$file 2>/dev/null; then \
 			install -m 644 doc/examples/$$file $(DESTDIR)$(PREFIX)/share/ikiwiki/examples/$$file; \
 		fi; \
