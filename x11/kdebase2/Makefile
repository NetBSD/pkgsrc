# $NetBSD: Makefile,v 1.24 2001/09/07 14:34:33 drochner Exp $

DISTNAME=	kdebase-2.1.1
CATEGORIES=	x11 kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Base modules for the KDE 2 integrated X11 desktop

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.png Daemon.README

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake
BUILD_DEPENDS+=		{qt2-designer>=2.2.4,qt2-designer-kde>=2.3.1nb1}:../../x11/qt2-designer

USE_BUILDLINK_ONLY=	yes

.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ENV+=		UIC="${QTDIR}/bin/uic"
CONFIGURE_ENV+=		USER_LDFLAGS="${USER_LDFLAGS}"
CONFIGURE_ARGS+=	--with-motif-includes="${BUILDLINK_DIR}/include"
CONFIGURE_ARGS+=	--with-motif-libraries="${BUILDLINK_DIR}/lib"
CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_DIR}"
CONFIGURE_ARGS+=	--disable-greet-lib
CONFIGURE_ARGS+=	--without-pam
LIBS+=			-Wl,--export-dynamic
USER_LDFLAGS=		-L${BUILDLINK_DIR}/lib
USER_LDFLAGS+=		-Wl,-R${LOCALBASE}/lib
USER_LDFLAGS+=		-Wl,-R${X11BASE}/lib

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
IMAKEDIR=	${WRKDIR}/imake

CONFIGURE_ENV+=	GL_INCLUDE="${BUILDLINK_DIR}/include"

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "a.out"
BROKEN=		"This package doesn't build on a.out. This is being worked on."
.endif

PLIST_INIT=	${PKGDIR}/PLIST
PLIST_SRC=	${WRKDIR}/PLIST
PLIST_DIRS=	share/kde/applnk \
		share/kde/apps/kappfinder

KDE_RPATH_MAKEFILES=	kcontrol/ebrowsing/Makefile.in
KDE_RPATH_MAKEFILES+=	kcontrol/ebrowsing/plugins/ikws/Makefile.in
KDE_RPATH_MAKEFILES+=	kcontrol/ebrowsing/plugins/shorturi/Makefile.in
KDE_RPATH_MAKEFILES+=	kcontrol/kio/Makefile.in
KDE_RPATH_MAKEFILES+=	kcontrol/konq/Makefile.in
KDE_RPATH_MAKEFILES+=	kcontrol/konqhtml/Makefile.in

# Add a missing $(KDE_RPATH) to the LDFLAGS setting in several Makefiles.
post-patch:
	@cd ${WRKSRC};							\
	for file in ${KDE_RPATH_MAKEFILES}; do				\
		${SED}	-e "s,\(^LDFLAGS.*\),\1 \$$(KDE_RPATH),"	\
			$${file} > $${file}.add-kde-rpath;		\
		${MV} -f $${file}.add-kde-rpath $${file};		\
	done

post-configure:
	${MKDIR} ${IMAKEDIR}
	${LN} -fs ${FILESDIR}/Imakefile ${IMAKEDIR}
	cd ${IMAKEDIR} && \
	${XMKMF} && ${MAKE} hasxdmauth >>${WRKSRC}/kdm/kdm-config.h
	${RM} -rf ${IMAKEDIR}

pre-install:
	@# on some systems we only have libXdpms.a which makes libkcm_energy and 
	@# libkcm_screensaver to only build static libs.
	${RM} -f ${PLIST_SRC}
.if !exists(${X11BASE}/lib/libXdpms.a) || exists(${X11BASE}/lib/libXdpms.so)
	${ECHO} "lib/kde2/libkcm_energy.so" >> ${PLIST_SRC}
	${ECHO} "lib/kde2/libkcm_screensaver.so" >>${PLIST_SRC}
.endif
	${CAT} ${PLIST_INIT} >> ${PLIST_SRC}

post-install:
	@${CHMOD} u+s ${PREFIX}/bin/konsole_grantpty
	@${CHMOD} u+s ${PREFIX}/bin/ksysguardd
	@(cd ${PREFIX}; ${FIND} ${PLIST_DIRS} \! -type d | ${SORT})	\
		>> ${PLIST_SRC}
	@(cd ${PREFIX}; ${FIND} ${PLIST_DIRS} -type d | ${SORT} -r |	\
		${SED} "s/^/\@dirrm /")					\
		>> ${PLIST_SRC}
	@for DIR in ${KDE_DIRS}; do					\
		${INSTALL_DATA_DIR} ${PREFIX}/${DIR};			\
		${ECHO} "@exec mkdir -p %D/${DIR}" >>${PLIST_SRC};	\
		${ECHO} "@dirrm ${DIR}" >>${PLIST_SRC};			\
	done
	@# NetBSD Advertisement O:-)
	@cd ${PREFIX}/share/kde/config;					\
	${CP} kdmrc kdmrc.new;						\
	${SED} \
		-e 's|^\(GreetString\)=.*|\1=Welcome to ${OPSYS}! [HOSTNAME]|' \
		-e 's|^#\(LogoPixmap\)=.*|\1=${PREFIX}/share/kde/icons/Daemon.png|' \
		kdmrc.new > kdmrc;					\
	${RM} kdmrc.new
	@${INSTALL_DATA} ${DISTDIR}/Daemon.png ${PREFIX}/share/kde/icons
	@${INSTALL_DATA} ${DISTDIR}/Daemon.README			\
		${PREFIX}/share/doc/kde/HTML/en/kdm

.include "../../graphics/Mesa/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../x11/kdelibs2/buildlink.mk"
.include "../../x11/lesstif/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
