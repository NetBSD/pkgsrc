# $NetBSD: Makefile,v 1.3 2017/09/02 14:26:56 kleink Exp $

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
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-isort-[0-9]*:../../devel/py-test-isort
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
