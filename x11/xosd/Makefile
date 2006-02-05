# $NetBSD: Makefile,v 1.9 2006/02/05 23:11:48 joerg Exp $
#

PKGREVISION=		2

.include "Makefile.common"

COMMENT=		Library to display shaped text on your X display

CONFIGURE_ENV+=		XOSD_XMMS_PLUGIN=NO
CONFIGURE_ARGS+=	--disable-gdk_pixbuftest
CONFIGURE_ARGS+=	--disable-new-plugin

.include "../../mk/bsd.pkg.mk"
