# $NetBSD: Makefile,v 1.41 2002/09/11 15:13:02 tron Exp $

DISTNAME=	kdelibs-2.2.2
PKGREVISION=	3
CATEGORIES=	x11
COMMENT=	Support libraries for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

BUILDLINK_DEPENDS.audiofile=	libaudiofile>=0.1.9
BUILDLINK_DEPENDS.qt2-libs=	qt2-libs>=2.3.1nb2

USE_BUILDLINK2=		YES
USE_OPENSSL_VERSION=	${OPENSSL_VERSION_096}

CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_PREFIX.openssl}"
CONFIGURE_ENV+=		PKG_CONFIG=${WRKDIR}/must-not-exist

.if (${MACHINE_ARCH} == "arm32")
BROKEN=		Compilation causes arm32 machines to hang
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS+=			-Wl,--export-dynamic
.endif

GCC_VERSION!=		gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs) && (${MACHINE_ARCH} == alpha)
.  include "../../lang/gcc/Makefile.gcc"
.endif

REPLACE_PERL= \
	${WRKSRC}/kio/proxytype.pl \
	${WRKSRC}/kio/useragent.pl

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
