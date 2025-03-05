# $NetBSD: Makefile,v 1.11 2025/03/05 10:38:13 wiz Exp $

DISTNAME=	Routes-2.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=R/Routes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/Routes
COMMENT=	Python re-implementation of the Rails routes system for mapping URLs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-repoze.lru>=0.3:../../devel/py-repoze.lru
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
# middleware
DEPENDS+=	${PYPKGPREFIX}-WebOb-[0-9]*:../../www/py-WebOb
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-WebTest-[0-9]*:../../www/py-WebTest

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
