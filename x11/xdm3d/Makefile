# $NetBSD: Makefile,v 1.1 1998/08/19 21:13:18 tron Exp $

DISTNAME=		xdm3d-1.0
CATEGORIES=		x11
MASTER_SITES=		http://www.futureone.com/~garbled/

MAINTAINER=		root@garbled.net

WRKSRC=			${WRKDIR}/xdm
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdm ${PREFIX}/bin/xdm3d
	${MKDIR} ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/GiveConsole ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/TakeConsole ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/Xaccess ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/Xservers ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/Xsession ${PREFIX}/share/xdm3d
	-${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/Xsetup ${PREFIX}/share/xdm3d
	-${INSTALL_DATA} ${X11BASE}/lib/X11/xdm/Xsetup_0 ${PREFIX}/share/xdm3d
	${INSTALL_PROGRAM} ${X11BASE}/lib/X11/xdm/chooser ${PREFIX}/share/xdm3d
	${MKDIR} ${PREFIX}/share/xdm3d/authdir
	chmod 700 ${PREFIX}/share/xdm3d/authdir
	${SED} -e 's@/usr/X11R6/lib/X11/xdm@${PREFIX}/share/xdm3d@' < \
		${X11BASE}/lib/X11/xdm/xdm-config > \
		${PREFIX}/share/xdm3d/xdm-config
	${INSTALL_DATA} ${WRKSRC}/Xresources.3D ${PREFIX}/share/xdm3d/Xresources
	${ECHO} 'DisplayManager*loginmoveInterval:		10' >> \
		${PREFIX}/share/xdm3d/xdm-config

.include "../../mk/bsd.pkg.mk"
