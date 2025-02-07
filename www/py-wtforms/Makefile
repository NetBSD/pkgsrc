# $NetBSD: Makefile,v 1.21 2025/02/07 09:27:02 adam Exp $

DISTNAME=	wtforms-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://wtforms.readthedocs.io/
COMMENT=	Flexible forms validation and rendering library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-babel>=2.6.0:../../devel/py-babel
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
# email
DEPENDS+=	${PYPKGPREFIX}-email_validator-[0-9]*:../../mail/py-email_validator

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} > 311
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
