# $NetBSD: Makefile,v 1.8 2018/03/19 09:03:25 adam Exp $

DISTNAME=	PyJWT-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyJWT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jpadilla/pyjwt
COMMENT=	JSON Web Token implementation in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.4:../../security/py-cryptography
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pyjwt jwt-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
