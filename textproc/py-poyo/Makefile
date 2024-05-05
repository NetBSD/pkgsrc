# $NetBSD: Makefile,v 1.5 2024/05/05 22:19:47 wiz Exp $

DISTNAME=	poyo-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poyo/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/hackebrot/poyo
COMMENT=	YAML Parser for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
