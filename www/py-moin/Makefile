# $NetBSD: Makefile,v 1.5 2008/03/11 04:19:04 obache Exp $
#

DISTNAME=	moin-1.5.4
PKGNAME=	${PYPKGPREFIX}-moin-1.5.4
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=moin/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://moinmo.in/
COMMENT=	Python clone of WikiWiki

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PYDISTUTILSPKG=	# empty
PYTHON_VERSIONS_ACCEPTED=	24 23

REPLACE_INTERPRETER+=	env_python
REPLACE.env_python.old=	/usr/bin/env python
REPLACE.env_python.new= ${PYTHONBIN}
REPLACE_FILES.env_python=	wiki/server/moin*

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
