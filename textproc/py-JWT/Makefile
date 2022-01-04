# $NetBSD: Makefile,v 1.18 2022/01/04 20:54:51 wiz Exp $

DISTNAME=	PyJWT-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyJWT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jpadilla/pyjwt
COMMENT=	JSON Web Token implementation in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.3.1:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
