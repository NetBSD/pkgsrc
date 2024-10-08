# $NetBSD: Makefile,v 1.59 2024/10/08 17:44:26 adam Exp $

DISTNAME=	django_cms-4.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-cms/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.django-cms.org/
COMMENT=	Django content management system
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-classy-tags>=0.7.2:../../www/py-django-classy-tags
DEPENDS+=	${PYPKGPREFIX}-django-formtools>=2.1:../../www/py-django-formtools
DEPENDS+=	${PYPKGPREFIX}-django-sekizai>=0.7:../../www/py-django-sekizai
DEPENDS+=	${PYPKGPREFIX}-django-treebeard>=4.3:../../www/py-django-treebeard
DEPENDS+=	${PYPKGPREFIX}-djangocms-admin-style>=1.2:../../www/py-djangocms-admin-style
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} djangocms djangocms-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
