# $NetBSD: Makefile,v 1.8 2026/02/17 14:45:00 adam Exp $

DISTNAME=	django_stubs_ext-5.2.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-stubs-ext/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/typeddjango/django-stubs
COMMENT=	Monkey-patching and extensions for django-stubs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.8.22:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-django>=5.0:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
