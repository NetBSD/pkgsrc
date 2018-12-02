# $NetBSD: Makefile,v 1.11 2018/12/02 16:21:40 adam Exp $

DISTNAME=	PyJWT-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyJWT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jpadilla/pyjwt
COMMENT=	JSON Web Token implementation in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.4:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.7.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.5.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner>=4.2:../../devel/py-test-runner

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} pyjwt jwt-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
