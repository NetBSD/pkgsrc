# $NetBSD: Makefile,v 1.14 2024/08/08 08:59:49 adam Exp $

DISTNAME=	translate_toolkit-3.13.3
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
REPLACE_BASH+=	translate/convert/odfxml
REPLACE_BASH+=	translate/convert/roundtrip-OOo
REPLACE_BASH+=	translate/convert/roundtrip-gaia
REPLACE_BASH+=	translate/convert/roundtrip-mozilla

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
