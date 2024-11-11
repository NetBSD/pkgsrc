# $NetBSD: Makefile,v 1.6 2024/11/11 07:29:07 wiz Exp $

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

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
