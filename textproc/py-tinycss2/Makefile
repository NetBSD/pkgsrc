# $NetBSD: Makefile,v 1.2 2017/08/21 15:35:43 adam Exp $

DISTNAME=	tinycss2-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tinycss2/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://pythonhosted.org/tinycss2/
COMMENT=	Low-level CSS parser for Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-webencodings>=0.4:../../textproc/py-webencodings
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-isort-[0-9]*:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-cov

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
