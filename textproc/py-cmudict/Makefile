# $NetBSD: Makefile,v 1.24 2025/09/23 18:36:41 gutteridge Exp $

DISTNAME=	cmudict-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmudict/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/prosegrinder/python-cmudict
COMMENT=	Versioned Python wrapper package for cmudict
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=5.0:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=5.0:../../devel/py-importlib-resources

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
