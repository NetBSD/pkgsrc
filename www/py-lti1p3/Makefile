# $NetBSD: Makefile,v 1.1 2022/09/01 12:06:12 markd Exp $

DISTNAME=	PyLTI1p3-1.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/^py//}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylti1p3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dmitry-viskov/pylti1.3
COMMENT=	LTI 1.3 Advantage Tool implementation in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-JWT>=1.5:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-jwcrypto-[0-9]*:../../www/py-jwcrypto

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
