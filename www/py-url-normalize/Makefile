# $NetBSD: Makefile,v 1.3 2025/07/29 06:33:55 dkazankov Exp $

DISTNAME=	url_normalize-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/url_normalize/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/niksite/url-normalize
COMMENT=	URL normalization for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-idna>=3.3:../../www/py-idna

TEST_DEPENDS+=	${PYPKGPREFIX}-mypy-[0-9]*:../../lang/py-mypy
#TEST_DEPENDS+=	${PYPKGPREFIX}-pre-commit-[0-9]*:../../wip/py-pre-commit
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test_socket-[0-9]*:../../devel/py-test_socket
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-ruff-[0-9]*:../../devel/py-ruff

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} url-normalize url-normalize-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
