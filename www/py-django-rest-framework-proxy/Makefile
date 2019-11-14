# $NetBSD: Makefile,v 1.5 2019/11/14 17:34:28 adam Exp $

DISTNAME=	django-rest-framework-proxy-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-rest-framework-proxy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eofs/django-rest-framework-proxy/
COMMENT=	Easy proxying of incoming REST requests
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-djangorestframework-[0-9]*:../../www/py-djangorestframework

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-djangorestframework

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
