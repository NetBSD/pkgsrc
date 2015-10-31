# $NetBSD: Makefile,v 1.27 2015/10/31 14:18:32 schmonz Exp $

DISTNAME=		feedparser-5.2.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_PYPI:=f/feedparser/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/feedparser
COMMENT=		Parse RSS and Atom feeds in Python
LICENSE=		2-clause-bsd

USE_LANGUAGES=		#none

do-test:
	cd ${WRKSRC}/feedparser && ${PYTHONBIN} feedparsertest.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
