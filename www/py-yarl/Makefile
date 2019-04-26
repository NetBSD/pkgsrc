# $NetBSD: Makefile,v 1.19 2019/04/26 13:14:22 maya Exp $

DISTNAME=	yarl-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yarl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/yarl
COMMENT=	Yet another URL library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-idna>=2.0:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-multidict>=4.0:../../databases/py-multidict
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
