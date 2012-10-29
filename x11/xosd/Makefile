# $NetBSD: Makefile,v 1.12 2012/10/29 05:07:17 asau Exp $
#

#PKGREVISION=		1

.include "Makefile.common"

COMMENT=		Library to display shaped text on your X display

CONFIGURE_ENV+=		XOSD_XMMS_PLUGIN=NO
CONFIGURE_ARGS+=	--disable-gdk_pixbuftest
CONFIGURE_ARGS+=	--disable-new-plugin

.include "../../mk/bsd.pkg.mk"
