# $NetBSD: Makefile,v 1.92 2003/09/27 17:07:38 grant Exp $
# FreeBSD Id: Makefile,v 1.6 1997/11/27 00:35:27 se Exp

DISTNAME=	kdebase-1.1.2
PKGREVISION=	3
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_LOCAL}/kde1
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.png Daemon.README

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=       http://www.kde.org/
COMMENT=	Base modules for the KDE integrated X11 desktop

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_RMAN=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig
GNU_CONFIGURE=		YES

CONFIGURE_ARGS=	"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${QTDIR}/qt1"
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS} -DRMAN='\"${RMAN}\"'" \
		all_libraries="${KDE_LDFLAGS}"

FIX_RPATH+=	KDE_LDFLAGS
KDE_LDFLAGS=	-L${LOCALBASE}/lib -Wl,${RPATH_FLAG}${LOCALBASE}/lib -L${X11BASE}/lib -Wl,${RPATH_FLAG}${X11BASE}/lib

CFLAGS+=	-DPREFIX=\"\\\"${PREFIX}\\\"\"

EXTRACT_ONLY=	${DISTNAME}.tar.bz2
PLIST_SRC=	${WRKDIR}/PLIST
PLIST_DIRS=	share/kde/applnk share/kde/apps/kappfinder \
		share/kde/apps/kdisknav share/kde/icons share/kde/mimelnk

IMAKEDIR=	${WRKDIR}/imake
KDE_DIRS=	share/doc/kde/HTML/cs share/doc/kde/HTML/da \
		share/doc/kde/HTML/de share/doc/kde/HTML/el \
		share/doc/kde/HTML/fi share/doc/kde/HTML/fr \
		share/doc/kde/HTML/it share/doc/kde/HTML/no \
		share/doc/kde/HTML/pl share/doc/kde/HTML/pt \
		share/doc/kde/HTML/sv

CONFIGURE_ENV+= GL_INCLUDE="${BUILDLINK_PREFIX.Mesa}/include"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
PLIST_INIT=	${PKGDIR}/PLIST-${OPSYS}
.else
PLIST_INIT=	${PKGDIR}/PLIST
.endif

post-extract:
	@${LN} -fs ${FILESDIR}/info_netbsd.cpp ${WRKSRC}/kcontrol/info
	@${LN} -fs ${FILESDIR}/memory_netbsd.cpp ${WRKSRC}/kcontrol/info

post-configure:
	${MKDIR} ${IMAKEDIR}
	${LN} -fs ${FILESDIR}/Imakefile ${IMAKEDIR}
	cd ${IMAKEDIR} && \
	${XMKMF} && ${MAKE} hasxdmauth >>${WRKSRC}/kdm/kdm-config.h
	${RM} -rf ${IMAKEDIR}

post-install:
	@${CHMOD} u+s ${PREFIX}/bin/klock
	@${CHMOD} u+s ${PREFIX}/bin/*.kss
	@${CP} ${PLIST_INIT} ${PLIST_SRC}
	@(cd ${PREFIX}; ${FIND} ${PLIST_DIRS} -type f >>${PLIST_SRC})
	@(cd ${PREFIX}; ${FIND} ${PLIST_DIRS} -type d | sort -r | \
	    ${SED} "s/^/\@dirrm /" >>${PLIST_SRC})
.for DIR in ${KDE_DIRS}
	@${INSTALL_DATA_DIR} ${PREFIX}/${DIR}
	@${ECHO} "@exec mkdir -p %D/${DIR}" >>${PLIST_SRC}
	@${ECHO} "@dirrm ${DIR}" >>${PLIST_SRC}
.endfor
	#
	# NetBSD Advertisement O:-)
	cd ${PREFIX}/share/kde/config ; \
	${CP} kdmrc kdmrc.new ; \
	${SED} \
		-e 's|^\(GreetString\)=.*|\1=Welcome to ${OPSYS}! [HOSTNAME]|' \
		<kdmrc.new >kdmrc ; \
	${ECHO} 'LogoPixmap=${PREFIX}/share/kde/icons/Daemon.png' >>kdmrc ; \
	${RM} kdmrc.new
	${INSTALL_DATA} ${DISTDIR}/Daemon.png ${PREFIX}/share/kde/icons
	${INSTALL_DATA} ${DISTDIR}/Daemon.README \
	  ${PREFIX}/share/doc/kde/HTML/en/kdm
	#
	# Make template links writeable, to prevent "Permission denied"
	${CHMOD} u+w ${PREFIX}/share/kde/apps/kfm/Desktop/Templates/*.kdelnk

.include "../../mk/curses.buildlink2.mk"
# kdebase doesn't manipulate GIFs, but KDE packages depending on kdebase
# often do, so put the dependency here.
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/kdelibs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
