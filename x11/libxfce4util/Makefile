# $NetBSD: Makefile,v 1.14 2007/12/07 19:43:26 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4util-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce basic library

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
