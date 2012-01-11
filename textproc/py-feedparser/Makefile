# $NetBSD: Makefile,v 1.19 2012/01/11 23:31:44 schmonz Exp $
#

DISTNAME=		feedparser-5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		http://feedparser.googlecode.com/files/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://feedparser.googlecode.com/
COMMENT=		Parse RSS and Atom feeds in Python
LICENSE=		2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X=	yes

PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

do-test:
	cd ${WRKSRC}/feedparser && ${PYTHONBIN} feedparsertest.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
