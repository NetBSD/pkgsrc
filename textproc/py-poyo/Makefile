# $NetBSD: Makefile,v 1.7 2025/04/14 12:50:20 adam Exp $

DISTNAME=	poyo-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poyo/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/hackebrot/poyo
COMMENT=	YAML Parser for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
