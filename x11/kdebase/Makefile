# $NetBSD: Makefile,v 1.63 2000/03/28 00:12:31 dmcmahill Exp $
# FreeBSD Id: Makefile,v 1.6 1997/11/27 00:35:27 se Exp

DISTNAME=	kdebase-1.1.2
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/ \
		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.png Daemon.README

MAINTAINER=	tron@netbsd.org
HOMEPAGE=       http://www.kde.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/msgfmt:../../devel/gettext
DEPENDS+=	Mesa-*:../../graphics/Mesa
DEPENDS+=	kdelibs-1.1.2:../../x11/kdelibs
DEPENDS+=	xpm-3.4k:../../graphics/xpm
# kdebase doesn't manipulate GIFs, but KDE packages depending on kdebase
# often do, so put the dependency here.
#
DEPENDS+=	libungif-*:../../graphics/libungif

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${X11BASE}/qt1"
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -Wl,-R${X11BASE}/lib -L${X11BASE}/lib"

EXTRACT_ONLY=	${DISTNAME}.tar.bz2
PLIST_SRC=	${WRKDIR}/PLIST
PLIST_DIRS=	share/kde/applnk share/kde/apps/kappfinder \
		share/kde/apps/kdisknav share/kde/icons share/kde/mimelnk

KDE_DIRS=	share/doc/kde/HTML/cs share/doc/kde/HTML/da \
		share/doc/kde/HTML/de share/doc/kde/HTML/el \
		share/doc/kde/HTML/fi share/doc/kde/HTML/fr \
		share/doc/kde/HTML/it share/doc/kde/HTML/no \
		share/doc/kde/HTML/pl share/doc/kde/HTML/sv

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
PLIST_INIT=	${PKGDIR}/PLIST-${OPSYS}
.else
DEPENDS+=	ncurses>=4.2:../../devel/ncurses
PLIST_INIT=	${PKGDIR}/PLIST
.endif

post-extract:
	@${LN} -fs ${FILESDIR}/info_netbsd.cpp ${WRKSRC}/kcontrol/info
	@${LN} -fs ${FILESDIR}/memory_netbsd.cpp ${WRKSRC}/kcontrol/info

post-install:
	@${CHMOD} u+s ${PREFIX}/bin/klock
	@${CP} ${PLIST_INIT} ${PLIST_SRC}
	@(cd ${PREFIX}; ${FIND} ${PLIST_DIRS} -type f >>${PLIST_SRC})
	@(cd ${PREFIX}; ${FIND} ${PLIST_DIRS} -type d | sort -r | \
	    ${SED} "s/^/\@dirrm /" >>${PLIST_SRC})
.for DIR in ${KDE_DIRS}
	@${MKDIR} ${PREFIX}/${DIR}
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

.include "../../mk/bsd.pkg.mk"
