# $NetBSD: Makefile,v 1.5 2014/05/09 07:37:24 wiz Exp $

DISTNAME=	django-appmedia-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-appmedia/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/django-appmedia
COMMENT=	Handling django app media
LICENSE=	modified-bsd

EGG_NAME=		${DISTNAME:S/-/_/}
USE_LANGUAGES=		# empty
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.0.1

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
