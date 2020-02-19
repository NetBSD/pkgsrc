# $NetBSD: Makefile,v 1.3 2020/02/19 11:30:17 adam Exp $

DISTNAME=	djangocms-column-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-column/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-column
COMMENT=	Multi Column Plugin for django CMS
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.4.5:../../www/py-django-cms

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
