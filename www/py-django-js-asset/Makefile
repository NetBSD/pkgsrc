# $NetBSD: Makefile,v 1.13 2025/10/09 08:01:59 wiz Exp $

DISTNAME=	django_js_asset-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-js-asset/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matthiask/django-js-asset
COMMENT=	Script tag with additional attributes for django.forms.Media
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
