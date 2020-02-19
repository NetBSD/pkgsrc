# $NetBSD: Makefile,v 1.8 2020/02/19 11:20:54 adam Exp $

DISTNAME=	djangocms-file-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-file/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-file
COMMENT=	File plugin for django CMS
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.4.5:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-django-filer>=1.2.4:../../www/py-django-filer
DEPENDS+=	${PYPKGPREFIX}-djangocms-attributes-field>=0.4.0:../../www/py-djangocms-attributes-field

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-django-mptt

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
