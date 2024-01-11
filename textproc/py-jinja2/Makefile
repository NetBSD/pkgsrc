# $NetBSD: Makefile,v 1.36 2024/01/11 08:39:30 adam Exp $

DISTNAME=	Jinja2-3.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=J/Jinja2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jinja.palletsprojects.com/
COMMENT=	Small but fast and easy to use stand-alone template engine
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-babel>=2.7:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=2.0:../../textproc/py-markupsafe

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
