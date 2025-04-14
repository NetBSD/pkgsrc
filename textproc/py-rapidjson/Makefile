# $NetBSD: Makefile,v 1.23 2025/04/14 12:50:20 adam Exp $

DISTNAME=	python_rapidjson-1.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python_//}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-rapidjson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-rapidjson/python-rapidjson
COMMENT=	Python wrapper around rapidjson
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
