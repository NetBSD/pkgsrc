# $NetBSD: Makefile,v 1.1 2018/04/07 19:58:36 adam Exp $

DISTNAME=	drf-nested-routers-0.90.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/drf-nested-routers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alanjds/drf-nested-routers
COMMENT=	Nested resources for the Django Rest Framework
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-djangorestframework>=2.4.3:../../www/py-djangorestframework

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
