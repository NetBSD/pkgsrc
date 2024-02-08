# $NetBSD: Makefile,v 1.3 2024/02/08 22:57:24 adam Exp $

DISTNAME=	django-mailman3-1.3.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-mailman3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.list.org/
COMMENT=	Django library for Mailman UIs
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-allauth>=0.56:../../www/py-django-allauth
DEPENDS+=	${PYPKGPREFIX}-django-gravatar2>=1.0.6:../../www/py-django-gravatar2
DEPENDS+=	${PYPKGPREFIX}-mailmanclient>=3.3.3:../../mail/py-mailmanclient
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-django-[0-9]*:../../www/py-test-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
