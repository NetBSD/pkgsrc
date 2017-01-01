# $NetBSD: Makefile,v 1.8 2017/01/01 14:44:04 wiz Exp $

DISTNAME=	grappelli-safe-0.2.11
PKGNAME=	${PYPKGPREFIX}-django-mezzanine-${DISTNAME:S/-safe//}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/stephenmcd/grappelli-safe
COMMENT=	Snapshot of the Grappelli admin skin for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.2.11

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
