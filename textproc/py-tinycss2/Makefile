# $NetBSD: Makefile,v 1.17 2025/11/20 15:30:42 adam Exp $

DISTNAME=	tinycss2-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tinycss2/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/Kozea/tinycss2
COMMENT=	Low-level CSS parser for Python
LICENSE=	modified-bsd

EXTRACT_USING=	bsdtar

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-webencodings>=0.4:../../textproc/py-webencodings
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
