# $NetBSD: Makefile,v 1.56 2003/09/17 19:41:20 grant Exp $

DISTNAME=	kdelibs-2.2.2
PKGREVISION=	6
CATEGORIES=	x11
COMMENT=	Support libraries for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

CONFLICTS=	arts-[1-9]*

USE_BUILDLINK2=		YES
USE_GCC_SHLIB=		YES

CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_PREFIX.openssl}"
CONFIGURE_ENV+=		PKG_CONFIG=${WRKDIR}/must-not-exist

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "powerpc" && ${OPSYS} == "NetBSD")
CXXFLAGS+=-ftemplate-depth-30
.endif

.if ${OPSYS} == "NetBSD"
LIBS+=			-Wl,--export-dynamic
.endif
.if ${OPSYS} == "SunOS"
LIBS+=			`gcc -print-libgcc-file-name`
.endif

REPLACE_PERL= \
	kio/proxytype.pl \
	kio/useragent.pl

PLIST_SRC=		${WRKDIR}/PLIST
UNLIMIT_RESOURCES=	datasize

.if defined(USE_CUPS) && (${USE_CUPS} == "YES")
.  include "../../print/cups/buildlink2.mk"
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

# Add a newline to EOF so patch on Solaris succeeds with patch-bk

pre-patch:
	${ECHO} "" >> ${WRKSRC}/kio/klauncher/Makefile.am

# We will create the complete icon directory tree for use by other KDE2
# packages at post-install time.
#
ICONCOLORS=	hicolor locolor
ICONSIZES=	16x16 22x22 32x32 48x48 64x64
ICONDIRS=	actions/kde actions apps devices filesystems mimetypes

post-install:
	${RM} -f ${PREFIX}/share/kde/services/rlogin.protocol \
	  ${PREFIX}/share/kde/services/telnet.protocol
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

# XXX See below for NetBSD/alpha issues.
.if ${MACHINE_ARCH} == "alpha"
USE_PKGSRC_GCC=	# defined
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD=	3.0
.endif

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/qt2-libs/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"

# XXX On NetBSD, the egcs and gcc-2.95.3 for:
# XXX
# XXX     alpha
# XXX
# XXX have an optimization bug when compiling with -O2 that is tickled by:
# XXX
# XXX	${WRKSRC}/kdeprint/management/kmiconview.cpp
# XXX	${WRKSRC}/kdecore/kwinmodule.cpp
#
.if ${OPSYS} == "NetBSD"
.  if (${MACHINE_ARCH} == "alpha")
CXXFLAGS:=	${CXXFLAGS:C/-O[0-9]*//g}
CFLAGS:=	${CFLAGS:C/-O[0-9]*//g}
CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS}"
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}"
.  endif
.endif
