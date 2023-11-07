# $NetBSD: Makefile,v 1.27 2023/11/07 22:38:10 wiz Exp $

DISTNAME=	web.py-0.62
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/web.py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://webpy.org/
COMMENT=	Simple, public domain web publishing system
LICENSE=	public-domain

DEPENDS+=	${PYPKGPREFIX}-cheroot>=6.0.0:../../www/py-cheroot
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.4.1:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
