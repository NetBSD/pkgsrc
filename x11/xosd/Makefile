# $NetBSD: Makefile,v 1.15 2019/11/03 09:14:21 rillig Exp $

.include "Makefile.common"

COMMENT=	Library to display shaped text on your X display
PKGREVISION=	1

CONFIGURE_ENV+=		XOSD_XMMS_PLUGIN=NO
CONFIGURE_ARGS+=	--disable-gdk_pixbuftest
CONFIGURE_ARGS+=	--disable-new-plugin

.include "../../mk/bsd.pkg.mk"
