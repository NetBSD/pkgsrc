# $NetBSD: Makefile,v 1.7 2024/02/09 13:44:49 adam Exp $

DISTNAME=	wagtailmenus-3.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wagtailmenus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rkhleics/wagtailmenus
COMMENT=	Menu system for the Wagtail CMS
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-django-cogwheels>=0.3:../../www/py-django-cogwheels
DEPENDS+=	${PYPKGPREFIX}-wagtail>=2.15:../../www/py-wagtail
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.8:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} \
		run --source=wagtailmenus runtests.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
