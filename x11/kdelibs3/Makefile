# $NetBSD: Makefile,v 1.85 2005/05/04 13:45:51 markd Exp $

DISTNAME=	kdelibs-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	x11
COMMENT=	Support libraries for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

CONFLICTS+=	koffice3<=1.1.1

USE_DIRS+=		xdg-1.2
USE_PERL5=		run
USE_PKGINSTALL=		YES

MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=		${PREFIX}/share/examples/kdelibs3/applications.menu \
			${PKG_SYSCONFDIR}/xdg/menus/applications.menu

CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_PREFIX.openssl}"

SGML_CATALOGS=		${PREFIX}/share/kde/apps/ksgmltools2/customization/catalog
SGML_CATALOGS+=		${PREFIX}/share/kde/apps/ksgmltools2/docbook/xml-dtd-4.1.2/docbook.cat
SGML_CATALOGS+=		${PREFIX}/share/kde/apps/ksgmltools2/docbook/xml-dtd-4.2/docbook.cat

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

LIBS.NetBSD+=			${EXPORT_SYMBOLS_LDFLAGS}

MAKE_DIRS+=	${KDE3_DIRS:O:S/^/${PREFIX}\//}

REPLACE_PERL= \
	dcop/dcopidlng/kalyptus \
	kio/proxytype.pl \
	kio/useragent.pl \
	kio/misc/fileshareset \
	kdeui/preparetips

UNLIMIT_RESOURCES=	datasize memorysize

SUBST_CLASSES+=			kdelibsfix
SUBST_STAGE.kdelibsfix=		pre-configure
SUBST_MESSAGE.kdelibsfix=	"Fixing hardcoded paths."
SUBST_FILES.kdelibsfix= \
	kdecore/kstandarddirs.cpp \
	kdeui/ksconfig.cpp \
	kio/kssl/kopenssl.cc
SUBST_SED.kdelibsfix=		-e 's:@LOCALBASE@:${LOCALBASE}:g' \
	-e 's:@PKGLOCALEDIR@:${PKGLOCALEDIR}:g'

SUBST_CLASSES+=		kdemagic
SUBST_STAGE.kdemagic=	pre-configure
SUBST_MESSAGE.kdemagic=	"Add LOCALBASE paths to magic file."
SUBST_FILES.kdemagic=	kio/magic
SUBST_SED.kdemagic=	-n -e 'p' -e 's:/usr/local/bin:${LOCALBASE}/bin:p'

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdelibs
PKG_SUPPORTED_OPTIONS=	cups
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
PLIST_SUBST+=		CUPS=
.else
CONFIGURE_ARGS+=	--disable-cups
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

.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gssapi=yes



post-install:
.if ${OPSYS} == "NetBSD"
.  if ${OS_VERSION:M1.5.[12]*} || ${OS_VERSION:M1.[0-4]*}
	@${RM} ${PREFIX}/lib/kded.*
.  endif
.endif

.if ${MACHINE_ARCH} == "alpha"
GCC_REQD+=		2.95
.endif

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/arts/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
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
#
# Configure finds these but apparently they are not ready for primetime
# and build will blow up as declarations in netdb.h are not visible
CONFIGURE_ENV+= ac_cv_func_getservbyname_r='no'
CONFIGURE_ENV+= ac_cv_func_getservbyport_r='no'
CONFIGURE_ENV+= ac_cv_func_getprotobyname_r='no'
.endif

.if ${OPSYS} == "SunOS"
# We require use of a recent enough libbz2 to have the BZ2_ prefixes
# so force this as configure gets this wrong on Solaris 9
CONFIGURE_ENV+= ac_cv_lib_bzip2='no'
.endif
