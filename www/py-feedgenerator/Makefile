# $NetBSD: Makefile,v 1.8 2025/08/24 16:04:20 wiz Exp $

DISTNAME=	feedgenerator-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/feedgenerator/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/getpelican/feedgenerator
COMMENT=	Standalone version of django.utils.feedgenerator, compatible with Py3k
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
