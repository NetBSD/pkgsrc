# $NetBSD: Makefile,v 1.25 2013/06/06 01:57:55 schmonz Exp $
#

DISTNAME=		feedparser-5.1.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		http://feedparser.googlecode.com/files/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://feedparser.googlecode.com/
COMMENT=		Parse RSS and Atom feeds in Python
LICENSE=		2-clause-bsd

USE_LANGUAGES=		#none

PYTHON_VERSIONS_INCLUDE_3X=	yes

do-test:
	cd ${WRKSRC}/feedparser && ${PYTHONBIN} feedparsertest.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
