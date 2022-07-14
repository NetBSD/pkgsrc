# $NetBSD: Makefile,v 1.26 2022/07/14 23:46:27 dholland Exp $

PKGNAME=	htmldoc-x11-${VERSION}
PKGREVISION=	1

CONFIGURE_ARGS+=	--with-gui

# FLTK version 1.4 is supported too
.include "../../x11/fltk13/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../www/htmldoc/Makefile.common"
.include "../../mk/bsd.pkg.mk"
