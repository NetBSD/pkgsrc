# $NetBSD: Makefile,v 1.4 2003/04/27 12:52:02 cjep Exp $

DISTNAME=		wdm-1.22.1
CATEGORIES=		x11 windowmaker
MASTER_SITES=		http://voins.program.ru/wdm/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://voins.program.ru/wdm/
COMMENT=		WINGs display manager

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_X11BASE=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-wdmdir=${WDM_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-nlsdir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--with-gfx-incs=${BUILDLINK_DIR}/include/WINGs
CONFIGURE_ARGS+=	--with-gfx-libs=${BUILDLINK_DIR}/lib

RCD_SCRIPTS=		wdm

WDM_SYSCONFDIR=		${PREFIX}/lib/X11/wdm

OWN_DIRS_PERMS+=	${WDM_SYSCONFDIR}/authdir/authfiles		\
			${ROOT_USER} ${ROOT_GROUP} 700
OWN_DIRS_PERMS+=	${WDM_SYSCONFDIR}/authdir/authdir		\
			${ROOT_USER} ${ROOT_GROUP} 700
OWN_DIRS_PERMS=		${WDM_SYSCONFDIR}/authdir			\
			${ROOT_USER} ${ROOT_GROUP} 700
OWN_DIRS=		${WDM_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

# User may define WDM_MANAGERS option to specfy a window manager
# different from WindowMaker. WDM_MANAGERS is a space-separated
# list of window managers to support.
.for WMANAGER in ${WDM_MANAGERS}
CONFIGURE_ARGS+=	--with-winmgr=${WMANAGER}
.endfor

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../wm/windowmaker/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
