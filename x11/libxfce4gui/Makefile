# $NetBSD: Makefile,v 1.27 2009/08/26 19:56:58 sno Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfcegui4-${XFCE4_VERSION}
PKGNAME=	libxfce4gui-${XFCE4_VERSION}
PKGREVISION=	2
CATEGORIES=	x11
COMMENT=	Xfce widget library

USE_TOOLS+=		msgfmt
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKGCONFIG_OVERRIDE=	libxfcegui4/libxfcegui4-1.0.pc.in

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
