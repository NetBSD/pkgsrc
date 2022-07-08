# $NetBSD: Makefile,v 1.50 2022/07/08 15:08:02 wiz Exp $

DISTNAME=		xkeyboard-config-2.34
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=data/${PKGBASE}/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.freedesktop.org/wiki/Software/XKeyboardConfig
COMMENT=		X Keyboard Configuration Database

BUILD_DEPENDS+=		xkbcomp-[0-9]*:../../x11/xkbcomp

CONFLICTS+=		xkbdata-[0-9]*

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt perl pkg-config
PKGCONFIG_OVERRIDE+=	xkeyboard-config.pc.in
PYTHON_FOR_BUILD_ONLY=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		XKBCOMPDIR

CONFIGURE_ARGS+=	--with-xkb-rules-symlink=xfree86,xorg
CONFIGURE_ARGS+=	--with-xkb-base=${XKBBASE:Q}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--without-xsltproc
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
BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.4.3
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
