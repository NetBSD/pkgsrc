#
# $NetBSD: sitecustomize.py,v 1.1 2008/01/06 15:51:39 taca Exp $
#
# Set default character encoding for Zope.
#

import os, sys

env = os.environ

try :
  	encoding = env['ZOPE@ZOPE_VERSION@_DEFAULT_ENCODING']
	sys.setdefaultencoding(encoding)
except:
	pass
