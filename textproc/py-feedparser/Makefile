# $NetBSD: Makefile,v 1.17 2011/03/16 16:43:35 drochner Exp $
#

DISTNAME=		feedparser-5.0.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		http://feedparser.googlecode.com/files/
EXTRACT_SUFX=		.zip

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://feedparser.googlecode.com/
COMMENT=		Parse RSS and Atom feeds in Python

# XXXschmonz: python 2.4 -> 3.1
PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

do-test:
	cd ${WRKSRC}/feedparser && ${PYTHONBIN} feedparsertest.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
