# $NetBSD: Makefile,v 1.18 2007/12/20 11:56:45 obache Exp $

DISTNAME=		xdm3d-1.0
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.hijinks.com/~spade/linux/XBanner/
COMMENT=		Replacement for xdm with 3D effects

WRKSRC=			${WRKDIR}/xdm
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

PLIST_SRC=		${WRKDIR}/PLIST-src
INSTALLATION_DIRS=	bin

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if exists(${X11BASE}/lib/X11/xdm)
XDMDIR=${X11BASE}/lib/X11/xdm
.elif exists(/etc/X11/xdm)
XDMDIR=/etc/X11/xdm
.else
PKG_FAIL_REASON+=	"Cannot find xdm directory."
.endif

do-install:
	${ECHO} "${X11BASE} ${XDMDIR}"
	${INSTALL_PROGRAM} ${WRKSRC}/xdm ${DESTDIR}${PREFIX}/bin/xdm3d
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${XDMDIR}/GiveConsole ${DESTDIR}${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${XDMDIR}/TakeConsole ${DESTDIR}${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${XDMDIR}/Xaccess ${DESTDIR}${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${XDMDIR}/Xservers ${DESTDIR}${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${XDMDIR}/Xsession ${DESTDIR}${PREFIX}/share/xdm3d
	@if [ -r ${XDMDIR}/Xsetup ]; then			\
		${INSTALL_DATA} ${XDMDIR}/Xsetup ${DESTDIR}${PREFIX}/share/xdm3d; \
		sedexpr='-e s|^share/xdm3d/Xsetup_0$$|@comment\ &|';	\
	elif [ -r ${XDMDIR}/Xsetup_0 ]; then		\
		${INSTALL_DATA} ${XDMDIR}/Xsetup_0 ${DESTDIR}${PREFIX}/share/xdm3d; \
		sedexpr='-e s|^share/xdm3d/Xsetup$$|@comment\ &|';	\
	fi;								\
	${SED} "$$sedexpr" ${PKGDIR}/PLIST > ${PLIST_SRC}
	@if [ -r ${XDMDIR}/chooser ]; then				\
		${INSTALL_PROGRAM} ${XDMDIR}/chooser ${DESTDIR}${PREFIX}/share/xdm3d;		\
	elif [ -r ${X11BASE}/libexec/cooser ]; then			\
		${INSTALL_PROGRAM} ${X11BASE}/libexec/chooser ${DESTDIR}${PREFIX}/share/xdm3d;	\
	else								\
		${INSTALL_PROGRAM} ${WRKSRC}/chooser ${DESTDIR}${PREFIX}/share/xdm3d;		\
	fi
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/xdm3d/authdir
	${CHMOD} 700 ${DESTDIR}${PREFIX}/share/xdm3d/authdir
	${SED} -e 's@${XDMDIR}@${PREFIX}/share/xdm3d@' < \
		${XDMDIR}/xdm-config > \
		${DESTDIR}${PREFIX}/share/xdm3d/xdm-config
	${INSTALL_DATA} ${WRKSRC}/Xresources.3D ${DESTDIR}${PREFIX}/share/xdm3d/Xresources
	${ECHO} 'DisplayManager*loginmoveInterval:		10' >> \
		${DESTDIR}${PREFIX}/share/xdm3d/xdm-config

.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
