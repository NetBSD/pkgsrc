# $NetBSD: Makefile,v 1.1 2017/06/05 15:23:01 adam Exp $

DISTNAME=	django-rest-framework-proxy-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-rest-framework-proxy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/eofs/django-rest-framework-proxy/
COMMENT=	Easy proxying of incoming REST requests
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-djangorestframework-[0-9]*:../../www/py-django

USE_LANGUAGES=		# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
