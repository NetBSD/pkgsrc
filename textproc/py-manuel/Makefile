# $NetBSD: Makefile,v 1.6 2024/11/16 18:04:29 adam Exp $

DISTNAME=	manuel-1.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/manuel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/benji-york/manuel
COMMENT=	Build tested documentation
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testing-[0-9]*:../../devel/py-zope.testing

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
