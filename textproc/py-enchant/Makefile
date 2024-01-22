# $NetBSD: Makefile,v 1.19 2024/01/22 13:28:38 adam Exp $

DISTNAME=	pyenchant-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyenchant/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyenchant.github.io/pyenchant/
COMMENT=	Spellchecking library for Python
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	enchant2-[0-9]*:../../textproc/enchant2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"

SOEXT.dylib=	dylib
SOEXT=		${SOEXT.${SHLIB_TYPE}:Uso}
MAKE_ENV+=	PYENCHANT_LIBRARY_PATH=${PREFIX}/lib/libenchant-2.${SOEXT}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
