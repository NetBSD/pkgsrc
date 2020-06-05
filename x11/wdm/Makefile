# $NetBSD: Makefile,v 1.66 2020/06/05 12:49:17 jperkin Exp $

DISTNAME=		wdm-1.28
PKGREVISION=		21
CATEGORIES=		x11 windowmaker
#MASTER_SITES=		http://voins.program.ru/wdm/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://voins.program.ru/wdm/
COMMENT=		WINGs display manager
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		msgfmt pkg-config
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

LDFLAGS.DragonFly=	-lintl -lfontconfig
LDFLAGS.SunOS+=		-lintl -lresolv

CONFIGURE_ARGS+=	--with-wdmdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-nlsdir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--with-gfx-incs=${BUILDLINK_DIR}/include/WINGs
CONFIGURE_ARGS+=	--with-gfx-libs=${BUILDLINK_DIR}/lib
CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log
CONFIGURE_ARGS+=	--with-runlockdir=${VARBASE}/run
CONFIGURE_ARGS+=	--with-fakehome=${VARBASE}/run/wdm
CONFIGURE_ENV+=		SYSTEM_SHELL=${SH:Q}

RCD_SCRIPTS=		wdm

PKG_SYSCONFSUBDIR=	wdm

BUILD_DEFS+=		VARBASE

OWN_DIRS_PERMS=		${PKG_SYSCONFDIR}/authdir			\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 700
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/authdir/authfiles		\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 700
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/authdir/authdir		\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 700

CONF_FILES=
.for f in	GiveConsole TakeConsole Xaccess Xclients Xclients.in	\
		Xresources Xservers Xservers.fs Xservers.ws Xsession	\
		Xsession.XFree86 Xsession.orig Xsetup_0 wdm-config	\
		wdm-config.in wdmReconfig
CONF_FILES+=	${PREFIX}/share/examples/wdm/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../mk/bsd.prefs.mk"

# User may define WDM_MANAGERS option to specfy a window manager
# different from WindowMaker. WDM_MANAGERS is a space-separated
# list of window managers to support.
.for wmanager in ${WDM_MANAGERS}
CONFIGURE_ARGS+=	--with-winmgr=${wmanager:Q}
.endfor

INSTALLATION_DIRS+=	share/pixmaps/wdm share/examples/wdm

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
