# $NetBSD: Makefile,v 1.10 2008/07/14 12:56:20 joerg Exp $
#

PKGREVISION=		2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

COMMENT=		Library to display shaped text on your X display

CONFIGURE_ENV+=		XOSD_XMMS_PLUGIN=NO
CONFIGURE_ARGS+=	--disable-gdk_pixbuftest
CONFIGURE_ARGS+=	--disable-new-plugin

.include "../../mk/bsd.pkg.mk"
