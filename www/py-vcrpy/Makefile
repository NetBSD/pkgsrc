# $NetBSD: Makefile,v 1.1 2024/08/10 14:35:12 wiz Exp $

DISTNAME=	vcrpy-6.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vcrpy/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/kevin1024/vcrpy
COMMENT=	VCR.py simplifies and speeds up tests that make HTTP requests
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-wrapt>=0:../../devel/py-wrapt
DEPENDS+=	${PYPKGPREFIX}-six>=1.5:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-yarl>=0:../../www/py-yarl
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.5:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpbin>=1.0.0:../../www/py-test-httpbin

# as of 6.0.1
# 60 failed, 173 passed, 9 skipped, 14 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
