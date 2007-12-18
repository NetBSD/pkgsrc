#
# $NetBSD: sitecustomize.py,v 1.1.1.1 2007/12/18 15:35:28 taca Exp $
#
# set default character encoding 
#

import os, sys

env = os.environ

try :
  	encoding = env['ZOPE210_DEFAULT_ENCODING']
	sys.setdefaultencoding(encoding)
except:
	pass
