# $NetBSD: Makefile,v 1.21.2.1 2012/05/27 13:26:24 spz Exp $
#

DISTNAME=		feedparser-5.1.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		http://feedparser.googlecode.com/files/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://feedparser.googlecode.com/
COMMENT=		Parse RSS and Atom feeds in Python
LICENSE=		2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		#none

do-test:
	cd ${WRKSRC}/feedparser && ${PYTHONBIN} feedparsertest.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
