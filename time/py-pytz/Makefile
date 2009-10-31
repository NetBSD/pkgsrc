# $NetBSD: Makefile,v 1.6 2009/10/31 03:07:11 wiz Exp $
#

DISTNAME=	pytz-2009n
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pytz/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://pytz.sourceforge.net/
COMMENT=	World timezone definitions, modern and historical
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
