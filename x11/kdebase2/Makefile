# $NetBSD: Makefile,v 1.27 2001/10/21 08:46:29 skrll Exp $

DISTNAME=	kdebase-2.2.1
CATEGORIES=	x11 kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Base modules for the KDE 2 integrated X11 desktop

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.png Daemon.README

BUILD_DEPENDS+=		{qt2-designer>=2.2.4,qt2-designer-kde>=2.3.1nb1}:../../x11/qt2-designer

USE_BUILDLINK_ONLY=	yes

.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ENV+=		UIC="${QTDIR}/bin/uic"
CONFIGURE_ENV+=		USER_LDFLAGS="${USER_LDFLAGS}"
CONFIGURE_ENV+=		GL_INCLUDE="${MESABASE}/include"
#CONFIGURE_ARGS+=	--with-motif-includes="${BUILDLINK_DIR}/include"
#CONFIGURE_ARGS+=	--with-motif-libraries="${BUILDLINK_DIR}/lib"
CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_DIR}"
CONFIGURE_ARGS+=	--disable-greet-lib
CONFIGURE_ARGS+=	--without-pam
LIBS+=			"-Wl,--export-dynamic"
USER_LDFLAGS=		-L${BUILDLINK_DIR}/lib
USER_LDFLAGS+=		-Wl,-R${LOCALBASE}/lib
USER_LDFLAGS+=		-Wl,-R${X11BASE}/lib

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

.include "../../mk/bsd.prefs.mk"

PLIST_INIT=		${PKGDIR}/PLIST
PLIST_SRC=		${WRKDIR}/PLIST
PLIST_DIRS=		share/kde/applnk \
			share/kde/apps/kappfinder

MKDIRS=	\
	share/kde/icons/hicolor/22x22/apps

post-build:
	@${SED} -e "s|@LOCALBASE@|${LOCALBASE}|" \
		< ${WRKSRC}/kioslave/info/kde-info2html.conf \
		> ${WRKSRC}/kioslave/info/kde-info2html.conf.new
	@${MV} \
		${WRKSRC}/kioslave/info/kde-info2html.conf.new \
		${WRKSRC}/kioslave/info/kde-info2html.conf

pre-install:
	${RM} -f ${PLIST_SRC}

post-install:
	# Check that this is still the case - the configure goop might do a better job
	@# on some systems libkcm_energy.so and libkcm_screensaver.so aren't created as
	@# the Xdpms stuff isn't available in a shared library
.if exists(${PREFIX}/lib/kde2/libkcm_energy.so)
	${ECHO} "lib/kde2/libkcm_energy.so" >> ${PLIST_SRC}
.endif
.if exists(${PREFIX}/lib/kde2/libkcm_screensaver.so)
	${ECHO} "lib/kde2/libkcm_screensaver.so" >>${PLIST_SRC}
.endif
	${CAT} ${PLIST_INIT} >> ${PLIST_SRC}
	@${CHMOD} u+s ${PREFIX}/bin/konsole_grantpty
	@${CHMOD} u+s ${PREFIX}/bin/kcheckpass
	@${CHMOD} u+s ${PREFIX}/bin/ksysguardd
	@(cd ${PREFIX}; ${FIND} ${PLIST_DIRS} \! -type d | sort >>${PLIST_SRC})
	@(cd ${PREFIX}; ${FIND} ${PLIST_DIRS} -type d | sort -r | \
		${SED} "s/^/\@dirrm /" >>${PLIST_SRC})
	@for DIR in ${MKDIRS}; do \
		${INSTALL_DATA_DIR} ${PREFIX}/$${DIR}; \
		${ECHO} "@exec mkdir -p %D/$${DIR}" >>${PLIST_SRC}; \
		${ECHO} "@dirrm $${DIR}" >>${PLIST_SRC}; \
	done
	@# NetBSD Advertisement O:-)
	cd ${PREFIX}/share/kde/config/kdm ; \
	${CP} kdmrc kdmrc.new ; \
	${SED} \
		-e 's|^#\(LogoPixmap\)=.*|\1=${PREFIX}/share/kde/icons/Daemon.png|' \
		<kdmrc.new >kdmrc ; \
	${RM} kdmrc.new
	@${INSTALL_DATA} ${DISTDIR}/Daemon.png ${PREFIX}/share/kde/icons
	@${INSTALL_DATA} ${DISTDIR}/Daemon.README \
		${PREFIX}/share/doc/kde/HTML/en/kdm

.include "../../graphics/Mesa/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../x11/kdelibs2/buildlink.mk"

.include "../../mk/bsd.pkg.mk"
