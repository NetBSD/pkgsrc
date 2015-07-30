# $NetBSD: Makefile,v 1.39 2015/07/30 14:55:44 abs Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4util-4.12.1
CATEGORIES=	x11

COMMENT=	Xfce basic library

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
