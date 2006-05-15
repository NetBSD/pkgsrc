# $NetBSD: Makefile,v 1.16 2006/05/15 21:56:56 joerg Exp $
#

DISTNAME=	acidlaunch-0.5
PKGREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	http://linuxgamers.net/download/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://linuxgamers.net/infoPage.php?page=acidlaunch
COMMENT=	Small, light-weight app launcher

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c++
CONFIGURE_ARGS+=	--disable-xmltest
CONFIGURE_ARGS+=	--disable-gdk_pixbuftest

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
