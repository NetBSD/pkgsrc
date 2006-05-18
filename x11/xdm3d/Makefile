# $NetBSD: Makefile,v 1.15 2006/05/18 20:30:02 wiz Exp $

DISTNAME=		xdm3d-1.0
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.spade.com/linux/XBanner/
COMMENT=		Replacement for xdm with 3D effects

BROKEN_IN=		pkgsrc-2006Q1

WRKSRC=			${WRKDIR}/xdm
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

PLIST_SRC=		${WRKDIR}/PLIST-src
INSTALLATION_DIRS=	bin

.include "../../mk/bsd.prefs.mk"

.if exists(${X11BASE}/lib/X11/xdm)
XDMDIR=${X11BASE}/lib/X11/xdm
.elif exists(/etc/X11/xdm)
XDMDIR=/etc/X11/xdm
.else
PKG_FAIL_REASON+=	"Cannot find xdm directory."
.endif

do-install:
	echo "${X11BASE} ${XDMDIR}"
	${INSTALL_PROGRAM} ${WRKSRC}/xdm ${PREFIX}/bin/xdm3d
	${INSTALL_DATA_DIR} ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${XDMDIR}/GiveConsole ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${XDMDIR}/TakeConsole ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${XDMDIR}/Xaccess ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${XDMDIR}/Xservers ${PREFIX}/share/xdm3d
	${INSTALL_DATA} ${XDMDIR}/Xsession ${PREFIX}/share/xdm3d
	@if [ -r ${XDMDIR}/Xsetup ]; then			\
		${INSTALL_DATA} ${XDMDIR}/Xsetup ${PREFIX}/share/xdm3d; \
		sedexpr='-e s|^share/xdm3d/Xsetup_0$$|@comment\ &|';	\
	elif [ -r ${XDMDIR}/Xsetup_0 ]; then		\
		${INSTALL_DATA} ${XDMDIR}/Xsetup_0 ${PREFIX}/share/xdm3d; \
		sedexpr='-e s|^share/xdm3d/Xsetup$$|@comment\ &|';	\
	fi;								\
	${SED} "$$sedexpr" ${PKGDIR}/PLIST > ${PLIST_SRC}
	${INSTALL_PROGRAM} ${XDMDIR}/chooser ${PREFIX}/share/xdm3d
	${INSTALL_DATA_DIR} ${PREFIX}/share/xdm3d/authdir
	${CHMOD} 700 ${PREFIX}/share/xdm3d/authdir
	${SED} -e 's@${XDMDIR}@${PREFIX}/share/xdm3d@' < \
		${XDMDIR}/xdm-config > \
		${PREFIX}/share/xdm3d/xdm-config
	${INSTALL_DATA} ${WRKSRC}/Xresources.3D ${PREFIX}/share/xdm3d/Xresources
	${ECHO} 'DisplayManager*loginmoveInterval:		10' >> \
		${PREFIX}/share/xdm3d/xdm-config

.include "../../mk/bsd.pkg.mk"
