# $NetBSD: Makefile,v 1.2.32.1 2020/02/09 19:14:23 bsiegert Exp $

DISTNAME=	feedgen-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/feedgen/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://lkiesow.github.io/python-feedgen
COMMENT=	Feed Generator (ATOM, RSS, Podcasts)
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
