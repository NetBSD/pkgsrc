# $NetBSD: Makefile,v 1.10 2025/04/14 19:31:54 adam Exp $

DISTNAME=	python_mimeparse-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-mimeparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/falconry/python-mimeparse
COMMENT=	Module provides basic functions for parsing mime-type names
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
