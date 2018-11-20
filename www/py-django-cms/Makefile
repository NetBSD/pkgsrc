# $NetBSD: Makefile,v 1.49 2018/11/20 17:13:32 adam Exp $

DISTNAME=	django-cms-3.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-cms/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.django-cms.org/
COMMENT=	Django content management system
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-classy-tags>=0.7.2:../../www/py-django-classy-tags
DEPENDS+=	${PYPKGPREFIX}-django-formtools>=1.0:../../www/py-django-formtools
DEPENDS+=	${PYPKGPREFIX}-django-sekizai>=0.7:../../www/py-django-sekizai
DEPENDS+=	${PYPKGPREFIX}-django-treebeard>=4.0.1:../../www/py-django-treebeard
DEPENDS+=	${PYPKGPREFIX}-djangocms-admin-style>=1.0:../../www/py-djangocms-admin-style

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
