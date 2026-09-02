# $NetBSD: Makefile,v 1.18 2026/09/02 14:16:32 adam Exp $

DISTNAME=	python_multipart-0.0.32
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-multipart/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/andrew-d/python-multipart
COMMENT=	Streaming multipart parser for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7.1.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
