# $NetBSD: Makefile,v 1.29 2025/04/24 14:16:03 wiz Exp $

PKGNAME=	htmldoc-x11-${VERSION}
PKGREVISION=	4

CONFIGURE_ARGS+=	--with-gui

# FLTK version 1.4 is supported too
.include "../../x11/fltk13/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../www/htmldoc/Makefile.common"
.include "../../mk/bsd.pkg.mk"
