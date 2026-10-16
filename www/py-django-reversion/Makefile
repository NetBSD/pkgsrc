# $NetBSD: Makefile,v 1.42 2026/10/16 19:44:26 adam Exp $

DISTNAME=	django_reversion-6.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-reversion/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/etianen/django-reversion
COMMENT=	Version control facilities for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django

USE_LANGUAGES=	# none

# https://github.com/etianen/django-reversion/issues/1001
PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
