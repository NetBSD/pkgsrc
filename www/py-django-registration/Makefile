# $NetBSD: Makefile,v 1.13 2023/07/13 10:03:29 wiz Exp $

DISTNAME=	django-registration-2.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-registration/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ubernostrum/django-registration
COMMENT=	User-registration application for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-confusable_homoglyphs>=3.0:../../converters/py-confusable_homoglyphs
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
