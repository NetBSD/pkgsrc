# $NetBSD: Makefile,v 1.41 2003/09/17 23:14:18 markd Exp $

DISTNAME=	kdelibs-3.1.4
CATEGORIES=	x11
COMMENT=	Support libraries for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

CONFLICTS+=	koffice3<=1.1.1

USE_BUILDLINK2=		YES
USE_GCC_SHLIB=		YES

CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_PREFIX.openssl}"


.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS+=			${EXPORT_SYMBOLS_LDFLAGS}
.endif

KDEDIR=			${PREFIX}

REPLACE_PERL= \
	kio/proxytype.pl \
	kio/useragent.pl \
	kdeui/preparetips

PLIST_SRC=		${WRKDIR}/PLIST
UNLIMIT_RESOURCES=	datasize memorysize

FOO_MAIN_FILES= \
	arts/knotify/knotify_main.cpp \
	dcop/dcopserver_main.cpp \
	kconf_update/kconf_update_main.cpp \
	kded/kbuildsycoca_main.cpp \
	kded/kded_main.cpp \
	kdeprint/management/kaddprinterwizard_main.cpp \
	kio/misc/kio_uiserver_main.cpp \
	kioslave/http/http_cache_cleaner_main.cpp \
	kioslave/http/kcookiejar/kcookiejar_main.cpp

.include "../../meta-pkgs/kde3/Makefile.foo_main"

FIXUP_FILES= \
	kspell/ksconfig.cpp \
	kio/kssl/kopenssl.cc

pre-configure:
	@for i in ${FIXUP_FILES}; do \
		${SED} -e 's:@LOCALBASE@:${LOCALBASE}:g' \
		     ${WRKSRC}/$${i} > ${WRKSRC}/$${i}.fixup && \
		${MV} ${WRKSRC}/$${i}.fixup ${WRKSRC}/$${i}; \
	done


.if defined(USE_CUPS) && (${USE_CUPS} == "YES")
.include "../../print/cups/buildlink2.mk"
BUILD_DEFS+=		USE_CUPS

PLIST_SUBST+=		CUPS=
.else
PLIST_SUBST+=		CUPS="@comment "
.endif

.if ${OPSYS} == "NetBSD"
.  if ${OS_VERSION:M1.5.[12]*} || ${OS_VERSION:M1.[0-4]*}
PLIST_SUBST+=		KDED_WORKAROUND="@comment "
.  else
PLIST_SUBST+=		KDED_WORKAROUND=""
.  endif
.else
PLIST_SUBST+=		KDED_WORKAROUND=""
.endif

# We will create the complete icon directory tree for use by other KDE3
# packages at post-install time.
#
ICONCOLORS=	hicolor locolor
ICONSIZES=	16x16 22x22 32x32 48x48 64x64
ICONDIRS=	actions/kde actions apps devices filesystems mimetypes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kde/locale
.if ${OPSYS} == "NetBSD"
.  if ${OS_VERSION:M1.5.[12]*} || ${OS_VERSION:M1.[0-4]*}
	@${RM} ${PREFIX}/lib/kded.*
.  endif
.endif
	@( ${CAT} ${PKGDIR}/PLIST;					\
	   for color in ${ICONCOLORS}; do				\
		colordir=share/kde/icons/$${color};			\
		for size in ${ICONSIZES}; do				\
			sizedir=$${colordir}/$${size};			\
			for dir in ${ICONDIRS}; do			\
				icondir=$${sizedir}/$${dir};		\
				${INSTALL_DATA_DIR} ${PREFIX}/$${icondir}; \
				${ECHO} "@exec ${MKDIR} %D/$${icondir}"; \
				${ECHO} "@dirrm $${icondir}";		\
			done;						\
			${ECHO} "@dirrm $${sizedir}";			\
		done;							\
		${ECHO} "@dirrm $${colordir}";				\
	  done;								\
	  ${ECHO} "@dirrm share/kde/icons";				\
	  ${ECHO} "@dirrm share/kde";					\
	) > ${PLIST_SRC}

.if ${MACHINE_ARCH} == "alpha"
USE_PKGSRC_GCC=		# defined
.endif

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../audio/arts/buildlink2.mk"
.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"

# XXX On NetBSD, the egcs and gcc-2.95.3 for:
# XXX
# XXX     alpha and sparc
# XXX
# XXX has an optimization bug when compiling with -O2 that is tickled by
# XXX ${WRKSRC}/kio/kio/global.cpp
# XXX ${WRKSRC}/kdeprint/management/kmiconview.cpp.
# XXX and others
#
.if ${OPSYS} == "NetBSD"
.  if (${MACHINE_ARCH} == "alpha" || ${MACHINE_ARCH} == "sparc")
CXXFLAGS:=      ${CXXFLAGS:C/-O[0-9]*/-O/g}
CFLAGS:=        ${CFLAGS:C/-O[0-9]*/-O/g}
CONFIGURE_ENV+= CXXFLAGS="${CXXFLAGS}"
CONFIGURE_ENV+= CFLAGS="${CFLAGS}"
.  endif
.endif
