# $NetBSD: Makefile,v 1.14 2011/02/28 14:53:09 wiz Exp $
#

DISTNAME=		xkeyboard-config-2.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=data/${PKGBASE}/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/wiki/Software/XKeyboardConfig
COMMENT=		X Keyboard Configuration Database

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		xkbcomp-[0-9]*:../../x11/xkbcomp

CONFLICTS+=		xkbdata-[0-9]*

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt
PKGCONFIG_OVERRIDE+=	xkeyboard-config.pc.in

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		XKBCOMPDIR

CONFIGURE_ARGS+=	--with-xkb-rules-symlink=xfree86,xorg
CONFIGURE_ARGS+=	--with-xkb-base=${XKBBASE:Q}
### In pkgsrc, we do this with INSTALL/DEINSTALL scripts.
###
CONFIGURE_ARGS+=	--disable-xkbcomp-symlink
###
REPLACE_SH=		rules/merge.sh
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

.include "../../mk/bsd.pkg.mk"
