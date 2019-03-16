# $NetBSD: Makefile,v 1.14 2019/03/16 08:50:47 bsiegert Exp $

.include "Makefile.common"

COMMENT=		Library to display shaped text on your X display
PKGREVISION=	1

CONFIGURE_ENV+=		XOSD_XMMS_PLUGIN=NO
CONFIGURE_ARGS+=	--disable-gdk_pixbuftest
CONFIGURE_ARGS+=	--disable-new-plugin

.include "../../mk/bsd.pkg.mk"
