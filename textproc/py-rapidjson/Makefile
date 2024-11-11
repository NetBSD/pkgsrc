# $NetBSD: Makefile,v 1.22 2024/11/11 07:29:07 wiz Exp $

DISTNAME=	python_rapidjson-1.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python_//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-rapidjson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-rapidjson/python-rapidjson
COMMENT=	Python wrapper around rapidjson
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
