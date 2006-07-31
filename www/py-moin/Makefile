# $NetBSD: Makefile,v 1.2 2006/07/31 17:06:50 joerg Exp $
#

DISTNAME=	moin-1.5.4
PKGNAME=	${PYPKGPREFIX}-moin-1.5.4
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=moin/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://moinmoin.wiwiwiwiweb.de/
COMMENT=	Python clone of WikiWiki

PYDISTUTILSPKG=	# empty
PYTHON_VERSIONS_ACCEPTED=	24 23

REPLACE_INTERPRETER+=	env_python
REPLACE.env_python.old=	/usr/bin/env python
REPLACE.env_python.new= ${PYTHONBIN}
REPLACE_FILES.env_python=	wiki/server/moin*

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
