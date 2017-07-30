# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:26 wiz Exp $

DISTNAME=	django-rest-framework-proxy-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-rest-framework-proxy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eofs/django-rest-framework-proxy/
COMMENT=	Easy proxying of incoming REST requests
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-djangorestframework-[0-9]*:../../www/py-django

USE_LANGUAGES=		# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
