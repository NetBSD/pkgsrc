$NetBSD: patch-googleapiclient_____init____.py,v 1.1 2016/10/19 12:58:32 wiz Exp $

Fix version:
https://github.com/google/google-api-python-client/compare/v1.5.4...master

--- googleapiclient/__init__.py.orig	2016-10-17 21:30:25.000000000 +0000
+++ googleapiclient/__init__.py
@@ -12,7 +12,7 @@
 # See the License for the specific language governing permissions and
 # limitations under the License.
 
-__version__ = "1.5.3"
+__version__ = "1.5.4"
 
 # Set default logging handler to avoid "No handler found" warnings.
 import logging
