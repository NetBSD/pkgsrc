# $NetBSD: Makefile,v 1.16 2025/01/27 12:03:16 adam Exp $

DISTNAME=	django_registration-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-registration/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ubernostrum/django-registration
COMMENT=	User-registration application for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-confusable_homoglyphs>=3.0:../../converters/py-confusable_homoglyphs
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
