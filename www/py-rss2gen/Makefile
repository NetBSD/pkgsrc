# $NetBSD: Makefile,v 1.5 2011/12/03 00:02:17 joerg Exp $

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

PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
