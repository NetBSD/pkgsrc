# $NetBSD: Makefile,v 1.1 2013/01/03 14:10:45 ryoon Exp $
#

DISTNAME=	filebrowser-safe-0.2.13
PKGNAME=	${PYPKGPREFIX}-django-mezzanine-${DISTNAME:S/-safe//}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/stephenmcd/filebrowser-safe/
COMMENT=	django-filebrowser for Mezzanine CMS
LICENSE=	modified-bsd

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
