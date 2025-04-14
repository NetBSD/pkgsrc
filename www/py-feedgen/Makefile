# $NetBSD: Makefile,v 1.7 2025/04/14 18:56:05 adam Exp $

DISTNAME=	feedgen-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/feedgen/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://feedgen.kiesow.be/
COMMENT=	Feed Generator (ATOM, RSS, Podcasts)
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
