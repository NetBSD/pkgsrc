# $NetBSD: Makefile,v 1.12 2001/05/01 09:46:36 skrll Exp $

DISTNAME=	kdebase-2.1
CATEGORIES=	x11 kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Base modules for the KDE 2 integrated X11 desktop

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.png Daemon.README

BUILD_DEPENDS+=	automake-1.4:../../devel/automake
BUILD_DEPENDS+=	qt2-designer>=2.2.4:../../x11/qt2-designer
DEPENDS+=	kdelibs-2.1nb1:../../x11/kdelibs2

USE_XPM=	yes
USE_MOTIF=	yes
.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ARGS+=	--disable-greet-lib
CONFIGURE_ENV+=	LIBS="-Wl,--export-dynamic"

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
IMAKEDIR=	${WRKDIR}/imake

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "a.out"
BROKEN=		"This package doesn't build on a.out. This is being worked on."
.endif

PLIST_INIT=	${PKGDIR}/PLIST
PLIST_SRC=	${WRKDIR}/PLIST
PLIST_DIRS=	share/kde/applnk \
		share/kde/apps/kappfinder

post-configure:
	${MKDIR} ${IMAKEDIR}
	${LN} -fs ${FILESDIR}/Imakefile ${IMAKEDIR}
	cd ${IMAKEDIR} && \
	${XMKMF} && ${MAKE} hasxdmauth >>${WRKSRC}/kdm/kdm-config.h
	${RM} -rf ${IMAKEDIR}

post-install:
	@${CHMOD} u+s ${PREFIX}/bin/konsole_grantpty
	@${CHMOD} u+s ${PREFIX}/bin/*.kss
	@${CHMOD} u+s ${PREFIX}/bin/ksysguardd
	@${CP} ${PLIST_INIT} ${PLIST_SRC}
	@(cd ${PREFIX}; ${FIND} ${PLIST_DIRS} \! -type d | sort >>${PLIST_SRC})
	@(cd ${PREFIX}; ${FIND} ${PLIST_DIRS} -type d | sort -r | \
	    ${SED} "s/^/\@dirrm /" >>${PLIST_SRC})
	@for DIR in ${KDE_DIRS}; do \
		${INSTALL_DATA_DIR} ${PREFIX}/${DIR}; \
		${ECHO} "@exec mkdir -p %D/${DIR}" >>${PLIST_SRC}; \
		${ECHO} "@dirrm ${DIR}" >>${PLIST_SRC}; \
	done
	@# NetBSD Advertisement O:-)
	@cd ${PREFIX}/share/kde/config ; \
	${CP} kdmrc kdmrc.new ; \
	${SED} \
		-e 's|^\(GreetString\)=.*|\1=Welcome to ${OPSYS}! [HOSTNAME]|' \
		-e 's|^#\(LogoPixmap\)=.*|\1=${PREFIX}/share/kde/icons/Daemon.png|' \
		<kdmrc.new >kdmrc ; \
	${RM} kdmrc.new
	@${INSTALL_DATA} ${DISTDIR}/Daemon.png ${PREFIX}/share/kde/icons
	@${INSTALL_DATA} ${DISTDIR}/Daemon.README \
	  ${PREFIX}/share/doc/kde/HTML/en/kdm

.include "../../mk/bsd.pkg.mk"
