# $NetBSD: Makefile,v 1.23 2026/02/26 11:04:39 adam Exp $

DISTNAME=	django_treebeard-5.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-treebeard/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django-treebeard/django-treebeard
COMMENT=	Efficient tree implementations for the Django Web Framework
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=5.2:../../www/py-django
TEST_DEPENDS+=	${PYPKGPREFIX}-test-django>=4.0:../../www/py-test-django
TEST_DEPENDS+=	${PYPKGPREFIX}-test-pythonpath>=0.7:../../devel/py-test-pythonpath

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
