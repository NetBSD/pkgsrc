# $NetBSD: Makefile,v 1.17 2004/10/03 00:18:38 tv Exp $

DISTNAME=		wdm-1.25
PKGREVISION=		3
CATEGORIES=		x11 windowmaker
MASTER_SITES=		http://voins.program.ru/wdm/

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://voins.program.ru/wdm/
COMMENT=		WINGs display manager

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PKGINSTALL=		YES
USE_X11BASE=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-wdmdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-nlsdir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--with-gfx-incs=${BUILDLINK_DIR}/include/WINGs
CONFIGURE_ARGS+=	--with-gfx-libs=${BUILDLINK_DIR}/lib
CONFIGURE_ENV+=		SYSTEM_SHELL="${SH}"

RCD_SCRIPTS=		wdm

PKG_SYSCONFSUBDIR=	wdm

OWN_DIRS_PERMS=		${PKG_SYSCONFDIR}/authdir			\
			${ROOT_USER} ${ROOT_GROUP} 700
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/authdir/authfiles		\
			${ROOT_USER} ${ROOT_GROUP} 700
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/authdir/authdir		\
			${ROOT_USER} ${ROOT_GROUP} 700

CONF_FILES=
.for f in	GiveConsole TakeConsole Xaccess Xclients Xclients.in	\
		Xresources Xservers Xservers.fs Xservers.ws Xsession	\
		Xsession.XFree86 Xsession.orig Xsetup_0 wdm-config	\
		wdm-config.in wdmReconfig
CONF_FILES+=	${PREFIX}/share/examples/wdm/$f ${PKG_SYSCONFDIR}/$f
.endfor
.undef f

.include "../../mk/bsd.prefs.mk"

# User may define WDM_MANAGERS option to specfy a window manager
# different from WindowMaker. WDM_MANAGERS is a space-separated
# list of window managers to support.
.for WMANAGER in ${WDM_MANAGERS}
CONFIGURE_ARGS+=	--with-winmgr=${WMANAGER}
.endfor

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps/wdm
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/wdm

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
