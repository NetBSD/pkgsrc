# $NetBSD: Makefile,v 1.1.1.1 2002/12/07 21:18:33 cjep Exp $

DISTNAME=		wdm-1.20
CATEGORIES=		x11
MASTER_SITES=		http://www.tcscs.com/wdm/wdm/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.tcscs.com/wdm/
COMMENT=		WINGs display manager

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gfx-incs=${BUILDLINK_DIR}/include/WINGs \
			--with-gfx-libs=${BUILDLINK_DIR}/lib

INSTALL_TARGET=		install-strip

WDM_AUTHDIR=		${PREFIX}/etc/wdm/authdir
WDM_EXTRADIR1=		${WDM_AUTHDIR}/authdir
WDM_EXTRADIR2=		${WDM_EXTRADIR1}/authfiles

# User may define WDM_MANAGERS option to specfy a window manager
# different from WindowMaker. WDM_MANAGERS is a space-separated
# list of window managers to support.
.for WMANAGER in ${WDM_MANAGERS}
CONFIGURE_ARGS+=	--with-winmgr=${WMANAGER}
.endfor

post-install:
	${MKDIR} ${WDM_EXTRADIR1}
	${CHMOD} 700 ${WDM_EXTRADIR1}
	${MKDIR} ${WDM_EXTRADIR2}
	${CHMOD} 700 ${WDM_EXTRADIR2}

.include "../../wm/windowmaker/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
