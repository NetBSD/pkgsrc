# $NetBSD: Makefile,v 1.3 2009/02/09 22:56:28 joerg Exp $
# FreeBSD: ports/japanese/zope-ejsplitter/Makefile,v 1.4 2005/03/22 04:10:23 danfe Exp
#

DISTNAME=	${ZOPE_PRODUCT_NAME}-${ZOPE_PRODUCT_VER}
PKGNAME=	${ZOPE_PKG_PREFIX}-${ZOPE_PRODUCT_NAME}-${ZOPE_PRODUCT_VER}
PKGREVISION=	1
CATEGORIES=	www python japanese
MASTER_SITES=	http://www005.upp.so-net.ne.jp/nakagami/Download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www005.upp.so-net.ne.jp/nakagami/tips/ZCTextIndex.html
COMMENT=	Japanese word splitter for searching text in Zope Products

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	24
ZOPE_VERSION_ACCEPTED=		29 210

ZOPE_PRODUCT_NAME=	ejSplitter
ZOPE_PRODUCT_VER=	0.5.1
WRKSRC=			${WRKDIR}/${ZOPE_PRODUCT_NAME}

.include "../../www/zope/product.mk"
.include "../../mk/bsd.pkg.mk"
