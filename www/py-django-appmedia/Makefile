# $NetBSD: Makefile,v 1.15 2022/01/04 20:55:18 wiz Exp $

DISTNAME=	django-appmedia-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-appmedia/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/django-appmedia
COMMENT=	Handling django app media
LICENSE=	modified-bsd

USE_LANGUAGES=		# empty
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.0.1

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
