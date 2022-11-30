# $NetBSD: Makefile,v 1.6 2022/11/30 09:33:05 adam Exp $

DISTNAME=	tinycss2-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tinycss2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/tinycss2/
COMMENT=	Low-level CSS parser for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-webencodings>=0.4:../../textproc/py-webencodings
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py27-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
