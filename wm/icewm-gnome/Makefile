# $NetBSD: Makefile,v 1.2 2001/02/17 17:21:41 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-gnome-/}

COMMENT=		small, fast and light-weight window manager (GNOME version)

DEPENDS+=		gnome-libs-*:../../x11/gnome-libs

CONFLICTS+=		icewm-[0-9]*

USE_X11=		yes

EVAL_PREFIX+=		GNOMEDIR=gnome-libs
CONFIGURE_ARGS+=	--with-gnome-menus="${GNOMEDIR}/bin/gnome-config"
CONFIGURE_ARGS+=	--with-imlib

.include "../../wm/icewm/Makefile.common"
