# $NetBSD: Makefile,v 1.56 2024/02/09 10:50:34 adam Exp $

DISTNAME=	django-cms-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} djangocms djangocms-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
