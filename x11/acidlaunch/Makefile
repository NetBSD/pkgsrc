# $NetBSD: Makefile,v 1.1.1.1 2002/05/22 12:58:57 zuntum Exp $
#

DISTNAME=	acidlaunch-0.5
CATEGORIES=	x11
MASTER_SITES=	http://linuxgamers.net/download/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://linuxgamers.net/infoPage.php?page=acidlaunch
COMMENT=	small, light-weight app launcher

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--disable-xmltest
CONFIGURE_ARGS+=	--disable-gdk_pixbuftest

.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../textproc/libxml2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
