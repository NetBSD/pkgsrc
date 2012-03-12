# $NetBSD: Makefile,v 1.13 2012/03/12 15:51:20 wiz Exp $
#

DISTNAME=	pytz-2012b
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pytz/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://pytz.sourceforge.net/
COMMENT=	World timezone definitions, modern and historical
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

# py-setuptools needed, but not available; package itself is ready
#PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
