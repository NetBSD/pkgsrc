# $NetBSD: Makefile,v 1.63 2026/11/01 21:41:57 wiz Exp $

DISTNAME=		xkeyboard-config-xkeyboard-config-2.49
PKGNAME=		${DISTNAME:S/xkeyboard-config-x/x/}
CATEGORIES=		x11
MASTER_SITES=		https://gitlab.freedesktop.org/xkeyboard-config/xkeyboard-config/-/archive/xkeyboard-config-${PKGVERSION_NOREV}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.freedesktop.org/wiki/Software/XKeyboardConfig
COMMENT=		X Keyboard Configuration Database

TOOL_DEPENDS+=		xkbcomp-[0-9]*:../../x11/xkbcomp
# generated man page is rather useless
#TOOL_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt

CONFLICTS+=		xkbdata-[0-9]*

USE_TOOLS+=		msgfmt perl pkg-config
PKGCONFIG_OVERRIDE+=	xkeyboard-config.pc.in
PYTHON_FOR_BUILD_ONLY=	tool

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		XKBCOMPDIR

MESON_ARGS+=		-Dxorg-rules-symlinks=true

###
### Keymaps, rules, etc. are installed here.
###
XKBBASE=		${PREFIX}/share/X11/xkb
###
### The server puts compiled keymaps in the directory below.
###
XKBCOMPDIR?=		${VARBASE}/db/xkb
###
### The package must symlink ${XKBCOMPDIR} into ${XKBBASE}. ${XKBCOMP} is
### is the path to the xkbcomp binary we wish to use.
###
XKBCOMPDIR_SYMLINK=	${XKBBASE}/compiled
XKBCOMP=		${PREFIX}/bin/xkbcomp

FILES_SUBST+=		XKBBASE=${XKBBASE:Q}
FILES_SUBST+=		XKBCOMP=${XKBCOMP:Q}
FILES_SUBST+=		XKBCOMP_SYMLINK=${${XKBBASE}/xkbcomp:L:Q}
FILES_SUBST+=		XKBCOMPDIR=${XKBCOMPDIR:Q}
FILES_SUBST+=		XKBCOMPDIR_SYMLINK=${XKBCOMPDIR_SYMLINK:Q}

OWN_DIRS+=		${XKBCOMPDIR}

BUILDLINK_DEPMETHOD.gettext=	build	# for the configure only
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.4.3
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
