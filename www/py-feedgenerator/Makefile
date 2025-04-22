# $NetBSD: Makefile,v 1.6 2025/04/22 21:17:00 wiz Exp $

DISTNAME=	feedgenerator-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/feedgenerator/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/getpelican/feedgenerator
COMMENT=	Standalone version of django.utils.feedgenerator, compatible with Py3k
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
