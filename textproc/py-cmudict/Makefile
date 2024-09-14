# $NetBSD: Makefile,v 1.20 2024/09/14 08:03:44 adam Exp $

DISTNAME=	cmudict-1.0.31
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmudict/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/prosegrinder/python-cmudict
COMMENT=	Versioned Python wrapper package for cmudict
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=5.0:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=5.0:../../devel/py-importlib-resources

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
