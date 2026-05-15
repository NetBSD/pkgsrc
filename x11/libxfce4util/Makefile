# $NetBSD: Makefile,v 1.86 2026/05/15 17:01:07 wiz Exp $

PKGREVISION= 5
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4util-4.20.1
CATEGORIES=	x11
MASTER_SITES+=	https://archive.xfce.org/src/xfce/libxfce4util/${PKGVERSION_NOREV:R}/

TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection

COMMENT=	Xfce basic library

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
