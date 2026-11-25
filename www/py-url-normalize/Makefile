# $NetBSD: Makefile,v 1.7 2026/11/25 12:16:13 adam Exp $

DISTNAME=	url_normalize-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/url_normalize/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/niksite/url-normalize
COMMENT=	URL normalization for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-idna>=3.20:../../www/py-idna
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test_socket>=0:../../devel/py-test_socket

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	url-normalize

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
