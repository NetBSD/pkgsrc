# $NetBSD: Makefile,v 1.67 2026/09/03 11:35:18 adam Exp $

DISTNAME=	django_cms-5.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-cms/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.django-cms.org/
COMMENT=	Django content management system
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-django>=5.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-classy-tags>=0.7.2:../../www/py-django-classy-tags
DEPENDS+=	${PYPKGPREFIX}-django-formtools>=2.1:../../www/py-django-formtools
DEPENDS+=	${PYPKGPREFIX}-django-sekizai>=0.7:../../www/py-django-sekizai
DEPENDS+=	${PYPKGPREFIX}-django-treebeard>=4.3:../../www/py-django-treebeard
# admin-style
DEPENDS+=	${PYPKGPREFIX}-djangocms-admin-style>=1.2:../../www/py-djangocms-admin-style

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	djangocms

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
