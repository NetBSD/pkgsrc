# $NetBSD: Makefile,v 1.25 2021/07/21 05:58:43 fcambus Exp $

PKGNAME=	htmldoc-x11-${VERSION}

CONFIGURE_ARGS+=	--with-gui

# FLTK version 1.4 is supported too
.include "../../x11/fltk13/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../www/htmldoc/Makefile.common"
.include "../../mk/bsd.pkg.mk"
