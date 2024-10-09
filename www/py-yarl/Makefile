# $NetBSD: Makefile,v 1.39 2024/10/09 08:23:20 adam Exp $

DISTNAME=	yarl-1.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yarl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/yarl
COMMENT=	Yet another URL library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-expandvars-[0-9]*:../../misc/py-expandvars
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=47:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-idna>=2.0:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-multidict>=4.0:../../databases/py-multidict
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults-[0-9]*:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.3.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
TOOL_DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
