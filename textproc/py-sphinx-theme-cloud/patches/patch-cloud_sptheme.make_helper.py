$NetBSD: patch-cloud_sptheme.make_helper.py,v 1.1 2012/12/20 13:32:34 darcy Exp $

- Wrap print string in parens to allow compiling by Python 3.x

--- cloud_sptheme/make_helper.py.orig	2012-07-31 18:11:55.000000000 +0000
+++ cloud_sptheme/make_helper.py
@@ -150,16 +150,16 @@ class SphinxMaker(object):
     #targets
     #===============================================================
     def target_help(self):
-        print "Please use \`make <target>' where <target> is one of"
-        print "  clean     remove all compiled files"
-        print "  html      to make standalone HTML files"
-        print "  servehtml to serve standalone HTML files on port 8000"
-#        print "  pickle    to make pickle files"
-#        print "  json      to make JSON files"
-        print "  htmlhelp  to make HTML files and a HTML help project"
-#        print "  latex     to make LaTeX files, you can set PAPER=a4 or PAPER=letter"
-#        print "  changes   to make an overview over all changed/added/deprecated items"
-#        print "  linkcheck to check all external links for integrity"
+        print ("Please use \`make <target>' where <target> is one of")
+        print ("  clean     remove all compiled files")
+        print ("  html      to make standalone HTML files")
+        print ("  servehtml to serve standalone HTML files on port 8000")
+#        print ("  pickle    to make pickle files")
+#        print ("  json      to make JSON files")
+        print ("  htmlhelp  to make HTML files and a HTML help project")
+#        print ("  latex     to make LaTeX files, you can set PAPER=a4 or PAPER=letter")
+#        print ("  changes   to make an overview over all changed/added/deprecated items")
+#        print ("  linkcheck to check all external links for integrity")
 
     def target_clean(self):
         rmpath(self.BUILD)
@@ -182,7 +182,7 @@ class SphinxMaker(object):
             # fall back to stdlib server
             import SimpleHTTPServer as s
             os.chdir(path)
-            print "Serving files from %r on port %r" % (path, port)
+            print ("Serving files from %r on port %r" % (path, port))
             s.BaseHTTPServer.HTTPServer(('',port), s.SimpleHTTPRequestHandler).serve_forever()
         else:
             serve(StaticURLParser(path), host="0.0.0.0", port=port)
@@ -191,8 +191,8 @@ class SphinxMaker(object):
 
     ##def target_latex(self):
     ##    build("latex")
-    ##    print "Run \`make all-pdf' or \`make all-ps' in that directory to" \
-    ##        "run these through (pdf)latex."
+    ##    print ("Run \`make all-pdf' or \`make all-ps' in that directory to"
+    ##        "run these through (pdf)latex.")
     ##
     ##def target_pdf():
     ##    assert os.name == "posix", "pdf build support not automated for your os"
@@ -200,7 +200,7 @@ class SphinxMaker(object):
     ##    target = BUILD / "latex"
     ##    target.chdir()
     ##    subprocess.call(['make', 'all-pdf'])
-    ##    print "pdf built"
+    ##    print ("pdf built")
 
     #===============================================================
     #helpers
@@ -217,9 +217,9 @@ class SphinxMaker(object):
 
         rc = subprocess.call([self.SPHINXBUILD, "-b", name] + ALLSPHINXOPTS + [ target ])
         if rc:
-            print "Sphinx-Build returned error, exiting."
+            print ("Sphinx-Build returned error, exiting.")
             sys.exit(rc)
-        print "Build finished. The %s pages are in %r." % (name, target,)
+        print ("Build finished. The %s pages are in %r." % (name, target,))
         return target
 
     def get_paper_opts(self):
