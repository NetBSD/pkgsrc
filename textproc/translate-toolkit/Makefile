# $NetBSD: Makefile,v 1.24 2025/03/14 15:47:24 adam Exp $

DISTNAME=	translate_toolkit-3.15.1
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/translate-toolkit/}

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://github.com/translate/translate
COMMENT=	Tools for working with translation files
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-cwcwidth>=0.1.10:../../devel/py-cwcwidth
DEPENDS+=	${PYPKGPREFIX}-lxml>=5.2.0:../../textproc/py-lxml

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run

REPLACE_BASH+=	tools/*
REPLACE_BASH+=	translate/convert/odfxml
REPLACE_BASH+=	translate/convert/roundtrip-OOo
REPLACE_BASH+=	translate/convert/roundtrip-gaia
REPLACE_BASH+=	translate/convert/roundtrip-mozilla

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
