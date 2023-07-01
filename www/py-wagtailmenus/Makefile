# $NetBSD: Makefile,v 1.5 2023/07/01 08:37:46 wiz Exp $

DISTNAME=	wagtailmenus-3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=rkhleics/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rkhleics/wagtailmenus
COMMENT=	Menu system for the Wagtail CMS
LICENSE=	mit

GITHUB_PROJECT=	wagtailmenus
GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-wagtail>=2.9:../../www/py-wagtail
DEPENDS+=	${PYPKGPREFIX}-django-cogwheels>=0.3:../../www/py-django-cogwheels
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} \
	    run --source=wagtailmenus runtests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
