# $NetBSD: Makefile,v 1.57 2004/04/20 12:22:22 markd Exp $

DISTNAME=	kdelibs-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	Support libraries for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

CONFLICTS+=	koffice3<=1.1.1

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PERL5=		run
USE_PKGINSTALL=		YES

CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_PREFIX.openssl}"

SGML_CATALOGS=		${PREFIX}/share/kde/apps/ksgmltools2/customization/catalog
SGML_CATALOGS+=		${PREFIX}/share/kde/apps/ksgmltools2/docbook/xml-dtd-4.1.2/docbook.cat
SGML_CATALOGS+=		${PREFIX}/share/kde/apps/ksgmltools2/docbook/xml-dtd-4.2/docbook.cat

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS+=			${EXPORT_SYMBOLS_LDFLAGS}
.endif

REPLACE_PERL= \
	kio/proxytype.pl \
	kio/useragent.pl \
	kdeui/preparetips

PLIST_SRC=		${WRKDIR}/PLIST
UNLIMIT_RESOURCES=	datasize memorysize

FIXUP_FILES= \
	kdeui/ksconfig.cpp \
	kio/kssl/kopenssl.cc

# Several programs need to be setuid-root, but due to the way that KDE3
# finds executables, the files must have their read bit set so that
# KStandardDir::findResource() will find them.
#
_KDE_SETUID_ROOT=	${ROOT_USER} ${ROOT_GROUP} 4755
SPECIAL_PERMS+=	${PREFIX}/bin/kgrantpty	${_KDE_SETUID_ROOT}

pre-configure:
	@for i in ${FIXUP_FILES}; do \
		${SED} -e 's:@LOCALBASE@:${LOCALBASE}:g' \
		     ${WRKSRC}/$${i} > ${WRKSRC}/$${i}.fixup && \
		${MV} ${WRKSRC}/$${i}.fixup ${WRKSRC}/$${i}; \
	done

.if defined(USE_CUPS) && (${USE_CUPS} == "YES")
.include "../../print/cups/buildlink3.mk"
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
ICONCOLORS=	crystalsvg hicolor locolor
ICONSIZES=	16x16 22x22 32x32 48x48 64x64 128x128
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

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/arts/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

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

.if ${OPSYS} == "SunOS"
# We require use of a recent enough libbz2 to have the BZ2_ prefixes
# so force this as configure gets this wrong on Solaris 9
CONFIGURE_ENV+= ac_cv_lib_bzip2='no'
.endif
