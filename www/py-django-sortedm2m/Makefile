# $NetBSD: Makefile,v 1.8 2025/09/03 14:44:24 adam Exp $

DISTNAME=	django-sortedm2m-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
#MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-sortedm2m/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=jazzband/}
GITHUB_PROJECT=	django-sortedm2m
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/django-sortedm2m
COMMENT=	Drop-in replacement for Django's many to many field
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
