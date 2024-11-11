# $NetBSD: Makefile,v 1.9 2024/11/11 07:29:26 wiz Exp $

DISTNAME=	python_mimeparse-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-mimeparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/falconry/python-mimeparse
COMMENT=	Module provides basic functions for parsing mime-type names
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=47:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
