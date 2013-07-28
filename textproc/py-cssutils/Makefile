# $NetBSD: Makefile,v 1.9 2013/07/28 17:26:08 kleink Exp $
#

DISTNAME=	cssutils-0.9.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/c/cssutils/
EXTRACT_SUFX=	.zip

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://cthedot.de/cssutils/
COMMENT=	Cascading Style Sheets parser and library for Python
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	#none

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	src/cssutils/*.py
REPLACE_FILES.python+=	src/cssutils/scripts/*.py

# all files are group/others writable.
post-extract:
	chmod -R go-w ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
