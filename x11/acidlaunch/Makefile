# $NetBSD: Makefile,v 1.4 2003/05/02 11:56:56 wiz Exp $
#

DISTNAME=	acidlaunch-0.5
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://linuxgamers.net/download/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://linuxgamers.net/infoPage.php?page=acidlaunch
COMMENT=	small, light-weight app launcher

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
CONFIGURE_ARGS+=	--disable-xmltest
CONFIGURE_ARGS+=	--disable-gdk_pixbuftest

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
