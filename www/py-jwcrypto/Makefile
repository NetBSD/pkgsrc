# $NetBSD: Makefile,v 1.11 2024/11/11 07:29:25 wiz Exp $

DISTNAME=	jwcrypto-1.5.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jwcrypto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/latchset/jwcrypto
COMMENT=	Implementation of JOSE Web standards
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	cryptography

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
