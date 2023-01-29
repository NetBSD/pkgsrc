# $NetBSD: Makefile,v 1.27 2023/01/29 21:18:04 ryoon Exp $

PKGNAME=	htmldoc-x11-${VERSION}
PKGREVISION=	2

CONFIGURE_ARGS+=	--with-gui

# FLTK version 1.4 is supported too
.include "../../x11/fltk13/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../www/htmldoc/Makefile.common"
.include "../../mk/bsd.pkg.mk"
