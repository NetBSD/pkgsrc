# $NetBSD: Makefile,v 1.11 2005/06/17 03:50:45 jlam Exp $

DISTNAME=		xdm3d-1.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.spade.com/linux/XBanner/
COMMENT=		Replacement for xdm with 3D effects

WRKSRC=			${WRKDIR}/xdm
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

PLIST_SRC=		${WRKDIR}/PLIST-src
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdm ${PREFIX}/bin/xdm3d
	${INSTALL_DATA_DIR} ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/GiveConsole ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/TakeConsole ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/Xaccess ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/Xservers ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/Xsession ${PREFIX}/share/xdm3d
	@if [ -r ${X11BASE}/lib/X11/xdm/Xsetup ]; then			\
		${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/Xsetup ${PREFIX}/share/xdm3d; \
		sedexpr='-e s|^share/xdm3d/Xsetup_0$$|@comment\ &|';	\
	elif [ -r ${X11BASE}/lib/X11/xdm/Xsetup_0 ]; then		\
		${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/Xsetup_0 ${PREFIX}/share/xdm3d; \
		sedexpr='-e s|^share/xdm3d/Xsetup$$|@comment\ &|';	\
	fi;								\
	${SED} "$$sedexpr" ${PKGDIR}/PLIST > ${PLIST_SRC}
	${INSTALL_PROGRAM} ${X11BASE}/lib/X11/xdm/chooser ${PREFIX}/share/xdm3d
	${INSTALL_DATA_DIR} ${PREFIX}/share/xdm3d/authdir
	${CHMOD} 700 ${PREFIX}/share/xdm3d/authdir
	${SED} -e 's@/usr/X11R6/lib/X11/xdm@${PREFIX}/share/xdm3d@' < \
		${X11BASE}/lib/X11/xdm/xdm-config > \
		${PREFIX}/share/xdm3d/xdm-config
	${INSTALL_DATA} ${WRKSRC}/Xresources.3D ${PREFIX}/share/xdm3d/Xresources
	${ECHO} 'DisplayManager*loginmoveInterval:		10' >> \
		${PREFIX}/share/xdm3d/xdm-config

.include "../../mk/bsd.pkg.mk"
