$NetBSD: patch-robobrowser_browser.py,v 1.1 2020/09/26 10:33:07 leot Exp $

Adjust for werkzeug 1.0.0.

--- robobrowser/browser.py.orig	2015-06-07 19:30:22.000000000 +0000
+++ robobrowser/browser.py
@@ -5,7 +5,7 @@ Robotic browser.
 import re
 import requests
 from bs4 import BeautifulSoup
-from werkzeug import cached_property
+from werkzeug.utils import cached_property
 from requests.packages.urllib3.util.retry import Retry
 
 from robobrowser import helpers
