# $NetBSD: Makefile,v 1.11 2008/10/02 12:18:27 joerg Exp $
#

DISTNAME=	moin-1.7.1
PKGNAME=	${PYPKGPREFIX}-moin-1.7.1
CATEGORIES=	www python
MASTER_SITES=	http://static.moinmo.in/files/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://moinmo.in/
COMMENT=	MoinMoin, a Python clone of WikiWiki

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PYTHON_VERSIONS_ACCEPTED=	25 24
PYDISTUTILSPKG=	# empty

REPLACE_INTERPRETER+=	env_python
REPLACE.env_python.old=	/usr/bin/env python
REPLACE.env_python.new= ${PYTHONBIN}
REPLACE_FILES.env_python=	wiki/server/moin*

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
