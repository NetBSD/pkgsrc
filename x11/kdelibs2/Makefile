# $NetBSD: Makefile,v 1.23 2001/12/03 15:37:20 skrll Exp $

DISTNAME=	kdelibs-2.2.2
CATEGORIES=	x11
COMMENT=	Support libraries for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

#DEPENDS+=	jade>=1.2.1:../../textproc/jade
BUILDLINK_DEPENDS.audiofile=  libaudiofile>=0.1.9

USE_BUILDLINK_ONLY=	YES
USE_PERL5=		YES
USE_OPENSSL_VERSION=	${OPENSSL_VERSION_096}

CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_DIR}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS+=			-Wl,--export-dynamic
.endif

# Override KDE_INCLUDES and QT_INCLUDES at build-time since their values
# are used by reference within the kdelibs2 Makefiles
#
MAKE_FLAGS+=		KDE_INCLUDES="-I${BUILDLINK_DIR}/include"
MAKE_FLAGS+=		QT_INCLUDES="-I${BUILDLINK_QTDIR}/include"

# The configure script looks for xml2-config in the environment as
# ${XML_CONFIG}, not as ${XML2_CONFIG} like it's supposed to.
#
CONFIGURE_ENV+=		XML_CONFIG="${XML2_CONFIG}"
KDEDIR=			${PREFIX}

REPLACE_PERL= \
	${WRKSRC}/kio/proxytype.pl \
	${WRKSRC}/kio/useragent.pl

PLIST_SRC=	${WRKDIR}/PLIST

# We will create the complete icon directory tree for use by other KDE2
# packages at post-install time.
#
ICONCOLORS=	hicolor locolor
ICONSIZES=	16x16 22x22 32x32 48x48 64x64
ICONDIRS=	actions/kde actions apps devices filesystems mimetypes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kde/locale
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

.include "../../archivers/bzip2/buildlink.mk"
.include "../../audio/libaudiofile/buildlink.mk"
.include "../../devel/pcre/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../print/cups/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../textproc/libxml2/buildlink.mk"
.include "../../textproc/libxslt/buildlink.mk"
.include "../../x11/kde2/buildlink.mk"
.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"

# XXX On NetBSD, the egcs for:
# XXX
# XXX     alpha
# XXX
# XXX has an optimization bug when compiling with -O2 that is tickled by
# XXX ${WRKSRC}/kdeprint/management/kmiconview.cpp.
#
.if ${OPSYS} == "NetBSD"
.  if (${MACHINE_ARCH} == "alpha")
CFLAGS+=	-O
.  endif
.endif
