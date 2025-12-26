# $NetBSD: Makefile,v 1.10 2025/12/26 16:40:40 adam Exp $

DISTNAME=	django_phonenumber_field-8.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-phonenumber-field/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stefanfoulis/django-phonenumber-field
COMMENT=	Django library for managing phone numbers
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
# phonenumbers
DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=7.0.2:../../textproc/py-phonenumbers

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
