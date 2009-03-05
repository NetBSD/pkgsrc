# $NetBSD: Makefile,v 1.2 2009/03/05 18:51:33 joerg Exp $

PYRSS2GENVER=	1.0.0
DISTNAME=	PyRSS2Gen-${PYRSS2GENVER}
PKGNAME=	${PYPKGPREFIX}-rss2gen-${PYRSS2GENVER}
CATEGORIES=	www python
MASTER_SITES=	http://www.dalkescientific.com/Python/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.dalkescientific.com/Python/PyRSS2Gen.html
COMMENT=	Python module to generate RSS feeds

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	# defined
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
