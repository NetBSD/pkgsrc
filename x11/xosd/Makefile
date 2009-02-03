# $NetBSD: Makefile,v 1.11 2009/02/03 19:59:41 shattered Exp $
#

#PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

COMMENT=		Library to display shaped text on your X display

CONFIGURE_ENV+=		XOSD_XMMS_PLUGIN=NO
CONFIGURE_ARGS+=	--disable-gdk_pixbuftest
CONFIGURE_ARGS+=	--disable-new-plugin

.include "../../mk/bsd.pkg.mk"
