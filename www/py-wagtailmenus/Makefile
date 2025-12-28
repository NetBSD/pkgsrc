# $NetBSD: Makefile,v 1.13 2025/12/28 08:28:01 adam Exp $

DISTNAME=	wagtailmenus-4.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wagtailmenus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rkhleics/wagtailmenus
COMMENT=	Menu system for the Wagtail CMS
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django-cogwheels>=0.3:../../www/py-django-cogwheels
DEPENDS+=	${PYPKGPREFIX}-wagtail>=6.3:../../www/py-wagtail
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.8:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.5:../../devel/py-coverage
#TEST_DEPENDS+=	${PYPKGPREFIX}-django-webtest>=1.9

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} \
		run --source=wagtailmenus runtests.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
