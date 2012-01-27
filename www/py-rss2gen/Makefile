# $NetBSD: Makefile,v 1.6 2012/01/27 07:00:22 obache Exp $

PYRSS2GENVER=	1.0.0
DISTNAME=	PyRSS2Gen-${PYRSS2GENVER}
PKGNAME=	${PYPKGPREFIX}-rss2gen-${PYRSS2GENVER}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.dalkescientific.com/Python/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.dalkescientific.com/Python/PyRSS2Gen.html
COMMENT=	Python module to generate RSS feeds
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	#none

PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
