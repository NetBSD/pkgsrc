# $NetBSD: Makefile,v 1.1.1.1 2000/12/12 02:03:48 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-gnome-/}

DEPENDS+=		gnome-libs-*:../../x11/gnome-libs

CONFLICTS+=		icewm-[0-9]*

USE_X11=		yes

EVAL_PREFIX+=		GNOMEDIR=gnome-libs
CONFIGURE_ARGS+=	--with-gnome-menus="${GNOMEDIR}/bin/gnome-config"
CONFIGURE_ARGS+=	--with-imlib

.include "../../wm/icewm/Makefile.common"
