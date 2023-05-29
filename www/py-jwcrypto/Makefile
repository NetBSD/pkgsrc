# $NetBSD: Makefile,v 1.3 2023/05/29 08:51:08 adam Exp $

DISTNAME=	jwcrypto-1.4.2
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

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
