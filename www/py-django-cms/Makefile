# $NetBSD: Makefile,v 1.53 2022/01/04 20:55:18 wiz Exp $

DISTNAME=	django-cms-3.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-cms/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.django-cms.org/
COMMENT=	Django content management system
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django2
DEPENDS+=	${PYPKGPREFIX}-django-classy-tags>=0.7.2:../../www/py-django-classy-tags
DEPENDS+=	${PYPKGPREFIX}-django-formtools>=2.1:../../www/py-django-formtools
DEPENDS+=	${PYPKGPREFIX}-django-sekizai>=0.7:../../www/py-django-sekizai
DEPENDS+=	${PYPKGPREFIX}-django-treebeard>=4.3:../../www/py-django-treebeard
DEPENDS+=	${PYPKGPREFIX}-djangocms-admin-style>=1.2:../../www/py-djangocms-admin-style

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
