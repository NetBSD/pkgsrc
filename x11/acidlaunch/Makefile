# $NetBSD: Makefile,v 1.22 2011/01/13 13:39:41 wiz Exp $
#

DISTNAME=	acidlaunch-0.5
PKGREVISION=	14
CATEGORIES=	x11
MASTER_SITES=	http://linuxgamers.net/download/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://linuxgamers.net/infoPage.php?page=acidlaunch
COMMENT=	Small, light-weight app launcher

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
CONFIGURE_ARGS+=	--disable-xmltest
CONFIGURE_ARGS+=	--disable-gdk_pixbuftest

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
