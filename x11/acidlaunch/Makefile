# $NetBSD: Makefile,v 1.10 2004/04/25 04:16:44 xtraeme Exp $
#

DISTNAME=	acidlaunch-0.5
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	http://linuxgamers.net/download/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://linuxgamers.net/infoPage.php?page=acidlaunch
COMMENT=	Small, light-weight app launcher

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
CONFIGURE_ARGS+=	--disable-xmltest
CONFIGURE_ARGS+=	--disable-gdk_pixbuftest

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
