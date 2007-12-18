# $NetBSD: Makefile,v 1.1.1.1 2007/12/18 00:28:14 bjs Exp $
#

DISTNAME=	xkeyboard-config-20071217
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/XKeyboardConfig
COMMENT=	X Keyboard Configuration Database

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		xkbdata-[0-9]*

GNU_CONFIGURE=		yes
USE_LANGUAGES=		# none
USE_TOOLS+=		gmake intltool perl:build 
USE_TOOLS+=		msgfmt msgmerge xgettext

CONFIGURE_ARGS+=	--with-xkb-rules-symlink=xfree86,xorg
CONFIGURE_ARGS+=	--with-xkb-base=${XKBBASE:Q}

### In pkgsrc, we do this with INSTALL/DEINSTALL scripts.
###
CONFIGURE_ARGS+=	--disable-xkbcomp-symlink

BUILD_DEPENDS+=		xkbcomp-[0-9]*:../../x11/xkbcomp
MAKE_JOBS_SAFE=		no
REPLACE_SH=		rules/merge.sh

### Keymaps, rules, etc. are installed here.
###
XKBBASE=		${PREFIX}/share/X11/xkb

### The server puts compiled keymaps in the directory below.
###
XKBCOMPDIR?=		${VARBASE}/db/xkb	

### The package must symlink ${XKBCOMPDIR} into ${XKBBASE}. ${XKBCOMP} is
### is the path to the xkbcomp binary we wish to use.
###
XKBCOMPDIR_SYMLINK=	${XKBBASE}/compiled
XKBCOMP=		${LOCALBASE}/bin/xkbcomp

BUILD_DEFS+=		VARBASE 
BUILD_DEFS+=		XKBCOMPDIR

FILES_SUBST+=		XKBBASE=${XKBBASE:Q}
FILES_SUBST+=		XKBCOMP=${XKBCOMP:Q}
FILES_SUBST+=		XKBCOMP_SYMLINK=${${XKBBASE}/xkbcomp:L:Q}
FILES_SUBST+=		XKBCOMPDIR=${XKBCOMPDIR:Q}
FILES_SUBST+=		XKBCOMPDIR_SYMLINK=${XKBCOMPDIR_SYMLINK:Q}

OWN_DIRS+=		${XKBCOMPDIR}

.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
