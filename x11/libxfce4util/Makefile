# $NetBSD: Makefile,v 1.7 2005/11/09 07:09:05 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	4.2.3.1

DISTNAME=	libxfce4util-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce basic library

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
