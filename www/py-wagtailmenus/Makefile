# $NetBSD: Makefile,v 1.10 2025/04/22 15:30:20 adam Exp $

DISTNAME=	wagtailmenus-4.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wagtailmenus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rkhleics/wagtailmenus
COMMENT=	Menu system for the Wagtail CMS
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django-cogwheels>=0.3:../../www/py-django-cogwheels
DEPENDS+=	${PYPKGPREFIX}-wagtail>=5.2:../../www/py-wagtail
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.8:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
#TEST_DEPENDS+=	${PYPKGPREFIX}-django-webtest>=1.9

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} \
		run --source=wagtailmenus runtests.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
