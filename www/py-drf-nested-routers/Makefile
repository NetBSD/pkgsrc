# $NetBSD: Makefile,v 1.8 2022/02/07 20:55:14 adam Exp $

DISTNAME=	drf-nested-routers-0.93.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/drf-nested-routers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alanjds/drf-nested-routers
COMMENT=	Nested resources for the Django Rest Framework
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-djangorestframework>=3.6.0:../../www/py-djangorestframework

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-djangorestframework

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
