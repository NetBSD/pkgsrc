# $NetBSD: Makefile,v 1.7 2008/04/25 20:39:13 joerg Exp $
#

DISTNAME=	moin-1.6.1
PKGNAME=	${PYPKGPREFIX}-moin-1.6.1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=moin/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://moinmo.in/
COMMENT=	Python clone of WikiWiki

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PYDISTUTILSPKG=	# empty

REPLACE_INTERPRETER+=	env_python
REPLACE.env_python.old=	/usr/bin/env python
REPLACE.env_python.new= ${PYTHONBIN}
REPLACE_FILES.env_python=	wiki/server/moin*

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
