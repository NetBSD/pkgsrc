# $NetBSD: Makefile,v 1.26 2026/10/16 19:44:26 adam Exp $

DISTNAME=	django_photologue-3.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-photologue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jdriscoll/django-photologue
COMMENT=	Plug-in photo management application for the Django framework
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=12.0.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-django>=5.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-sortedm2m>=4.0.0:../../www/py-django-sortedm2m

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
