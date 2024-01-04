# $NetBSD: Makefile,v 1.5 2024/01/04 22:29:23 adam Exp $

DISTNAME=	jwcrypto-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jwcrypto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/latchset/jwcrypto
COMMENT=	Implementation of JOSE Web standards
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-deprecated-[0-9]*:../../devel/py-deprecated

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	cryptography

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
