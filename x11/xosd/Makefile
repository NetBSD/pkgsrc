# $NetBSD: Makefile,v 1.8 2004/10/03 00:18:40 tv Exp $
#

PKGREVISION=		1

.include "Makefile.common"

COMMENT=		Library to display shaped text on your X display

CONFIGURE_ENV+=		XOSD_XMMS_PLUGIN=NO
CONFIGURE_ARGS+=	--disable-gdk_pixbuftest
CONFIGURE_ARGS+=	--disable-new-plugin

.include "../../mk/bsd.pkg.mk"
