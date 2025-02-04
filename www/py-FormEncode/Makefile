# $NetBSD: Makefile,v 1.12 2025/02/04 18:56:16 adam Exp $

DISTNAME=	formencode-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/FormEncode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://formencode.org/
COMMENT=	HTML form validation, generation, and conversion package
LICENSE=	python-software-foundation

WHEEL_NAME=	${DISTNAME:S/forme/FormE/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0.0:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-country-[0-9]*:../../geography/py-country
TEST_DEPENDS+=	${PYPKGPREFIX}-dns>=2:../../net/py-dns

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
