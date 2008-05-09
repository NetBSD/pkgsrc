# $NetBSD: Makefile,v 1.6.2.1 2008/05/09 10:21:15 rtr Exp $
#

DISTNAME=	moin-1.6.3
PKGNAME=	${PYPKGPREFIX}-moin-1.6.3
CATEGORIES=	www python
MASTER_SITES=	http://static.moinmo.in/files/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://moinmo.in/
COMMENT=	Python clone of WikiWiki

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PYDISTUTILSPKG=	# empty
PYTHON_VERSIONS_ACCEPTED=	24 23

REPLACE_INTERPRETER+=	env_python
REPLACE.env_python.old=	/usr/bin/env python
REPLACE.env_python.new= ${PYTHONBIN}
REPLACE_FILES.env_python=	wiki/server/moin*

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
