# $NetBSD: Makefile,v 1.1.1.1 2008/08/01 08:38:22 obache Exp $
#

DISTNAME=	Genshi-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
EGG_NAME=	${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://ftp.edgewall.com/pub/genshi/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://genshi.edgewall.org/
COMMENT=	Python toolkit for generation of output for the web

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c

DEPENDS+=	${PYPKGPREFIX}-babel>=0.8:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
