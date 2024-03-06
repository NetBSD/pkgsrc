# $NetBSD: Makefile,v 1.20 2024/03/06 21:39:44 wiz Exp $

DISTNAME=	wtforms-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://wtforms.readthedocs.io/
COMMENT=	Flexible forms validation and rendering library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-babel>=2.6.0:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-email_validator-[0-9]*:../../mail/py-email_validator
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# empty

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} > 311
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
.endif

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
