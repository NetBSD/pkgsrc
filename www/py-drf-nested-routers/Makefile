# $NetBSD: Makefile,v 1.11 2024/11/11 07:29:22 wiz Exp $

DISTNAME=	drf-nested-routers-0.94.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/drf-nested-routers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alanjds/drf-nested-routers
COMMENT=	Nested resources for the Django Rest Framework
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-djangorestframework>=3.14.0:../../www/py-djangorestframework

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
