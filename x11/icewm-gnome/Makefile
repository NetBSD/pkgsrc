# $NetBSD: Makefile,v 1.5 2000/07/18 15:21:01 agc Exp $

PKGNAME=		${DISTNAME:S/-/-gnome-/}

DEPENDS+=		gnome-libs-*:../../x11/gnome-libs

CONFLICTS+=		icewm-[0-9]*

USE_X11=		yes

EVAL_PREFIX+=		GNOMEDIR=gnome-libs
CONFIGURE_ARGS+=	--with-gnome-menus=${GNOMEDIR}/bin/gnome-config \
			--with-imlib
CONFIGURE_ENV+=		LIBS="-lintl"

.include "../../x11/icewm/Makefile.common"
