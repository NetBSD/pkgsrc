# $NetBSD: Makefile,v 1.7 2000/10/17 23:15:29 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-gnome-/}

DEPENDS+=		gnome-libs-*:../../x11/gnome-libs

CONFLICTS+=		icewm-[0-9]*

USE_X11=		yes

EVAL_PREFIX+=		GNOMEDIR=gnome-libs
CONFIGURE_ARGS+=	--with-gnome-menus="${GNOMEDIR}/bin/gnome-config"
CONFIGURE_ARGS+=	--with-imlib

.include "../../x11/icewm/Makefile.common"
