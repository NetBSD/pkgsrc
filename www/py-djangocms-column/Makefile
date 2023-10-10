# $NetBSD: Makefile,v 1.6 2023/10/10 16:49:05 adam Exp $

DISTNAME=	djangocms-column-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-column/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-column
COMMENT=	Multi Column Plugin for django CMS
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms>=3:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.8.0:../../www/py-django-cms

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
