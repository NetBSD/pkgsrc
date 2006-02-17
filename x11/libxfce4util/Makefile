# $NetBSD: Makefile,v 1.10 2006/02/17 06:49:25 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	4.2.3.2

DISTNAME=	libxfce4util-${XFCE4_VERSION}
#PKGREVISION=	1
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce basic library

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX:Q}/share/doc/html

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
