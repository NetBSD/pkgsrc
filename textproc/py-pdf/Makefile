# $NetBSD: Makefile,v 1.22 2024/03/11 13:18:00 wiz Exp $

DISTNAME=	pypdf-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/py-pdf/pypdf
COMMENT=	Pure-python PDF library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.9:../../devel/py-flit_core
# full
DEPENDS+=	${PYPKGPREFIX}-Pillow>=8.0.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0.0:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
