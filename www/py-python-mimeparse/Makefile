# $NetBSD: Makefile,v 1.7 2024/09/16 08:25:41 adam Exp $

DISTNAME=	python_mimeparse-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-mimeparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/falconry/python-mimeparse
COMMENT=	Module provides basic functions for parsing mime-type names
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=47:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.34:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
