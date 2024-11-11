# $NetBSD: Makefile,v 1.3 2024/11/11 07:29:25 wiz Exp $

DISTNAME=	PyLTI1p3-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/^py//}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylti1p3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dmitry-viskov/pylti1.3
COMMENT=	LTI 1.3 Advantage Tool implementation in Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-JWT>=1.5:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-jwcrypto-[0-9]*:../../www/py-jwcrypto
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
