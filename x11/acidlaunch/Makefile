# $NetBSD: Makefile,v 1.7 2003/12/04 19:48:26 xtraeme Exp $
#

DISTNAME=	acidlaunch-0.5
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://linuxgamers.net/download/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://linuxgamers.net/infoPage.php?page=acidlaunch
COMMENT=	Small, light-weight app launcher

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
CONFIGURE_ARGS+=	--disable-xmltest
CONFIGURE_ARGS+=	--disable-gdk_pixbuftest

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
