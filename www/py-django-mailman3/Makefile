# $NetBSD: Makefile,v 1.4 2024/03/09 06:24:30 adam Exp $

DISTNAME=	django_mailman3-1.3.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-mailman3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.list.org/
COMMENT=	Django library for Mailman UIs
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-allauth>=0.59:../../www/py-django-allauth
DEPENDS+=	${PYPKGPREFIX}-django-gravatar2>=1.0.6:../../www/py-django-gravatar2
DEPENDS+=	${PYPKGPREFIX}-mailmanclient>=3.3.3:../../mail/py-mailmanclient
TEST_DEPENDS+=	${PYPKGPREFIX}-test-django-[0-9]*:../../www/py-test-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
