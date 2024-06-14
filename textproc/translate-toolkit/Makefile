# $NetBSD: Makefile,v 1.9 2024/06/14 20:09:46 adam Exp $

DISTNAME=	translate_toolkit-3.13.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/translate-toolkit/}

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://github.com/translate/translate
COMMENT=	Tools for working with translation files
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.6.3:../../textproc/py-lxml

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run
REPLACE_BASH+=	tools/*

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
