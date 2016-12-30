# $NetBSD: Makefile,v 1.20 2016/12/30 12:54:21 wiz Exp $

PKGNAME=	htmldoc-x11-${VERSION}
PKGREVISION=	2

CONFIGURE_ARGS+=	--with-gui --with-x

.include "../../x11/fltk/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../www/htmldoc/Makefile.common"
.include "../../mk/bsd.pkg.mk"
