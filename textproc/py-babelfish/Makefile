# $NetBSD: Makefile,v 1.5 2024/10/14 06:08:40 wiz Exp $

DISTNAME=	babelfish-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/babelfish/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Diaoul/babelfish
COMMENT=	Python library to work with countries and languages
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.6:../../devel/py-importlib-metadata
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
