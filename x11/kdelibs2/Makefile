# $NetBSD: Makefile,v 1.66 2004/10/03 00:18:36 tv Exp $

DISTNAME=	kdelibs-2.2.2
PKGREVISION=	13
CATEGORIES=	x11
COMMENT=	Support libraries for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

CONFLICTS=	arts-[1-9]*

USE_BUILDLINK3=		YES
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
.  include "../../print/cups/buildlink3.mk"
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
GCC_REQD+=	2.95
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	3.0
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/kde2/kde2.mk"
.include "../../x11/qt2-libs/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

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
