# $NetBSD: Makefile,v 1.160 2012/09/15 10:07:08 obache Exp $

DISTNAME=	kdelibs-${_KDE_VERSION}
PKGREVISION=	18
CATEGORIES=	x11
COMMENT=	Support libraries for the KDE integrated X11 desktop

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde3/Makefile.kde3"

CONFLICTS+=	koffice3<=1.1.1
CONFLICTS=	kdelibs4-[0-9]*

USE_TOOLS+=		iceauth:run perl:run pkg-config

MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=		${PREFIX}/share/examples/kdelibs3/applications.menu \
			${PKG_SYSCONFDIR}/xdg/menus/applications.menu

CONFIGURE_ARGS+=	--with-distribution="NetBSD pkgsrc"
CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_PREFIX.openssl}"

SGML_CATALOGS=		${PREFIX}/share/kde/apps/ksgmltools2/customization/catalog
SGML_CATALOGS+=		${PREFIX}/share/kde/apps/ksgmltools2/docbook/xml-dtd-4.1.2/docbook.cat
SGML_CATALOGS+=		${PREFIX}/share/kde/apps/ksgmltools2/docbook/xml-dtd-4.2/docbook.cat

.include "../../mk/bsd.prefs.mk"

LIBS.NetBSD+=		${EXPORT_SYMBOLS_LDFLAGS}

REPLACE_PERL+= \
	dcop/dcopidlng/kalyptus \
	kio/proxytype.pl \
	kio/useragent.pl \
	kio/misc/fileshareset \
	kdeui/preparetips

CHECK_PORTABILITY_SKIP+=kate/tests/highlight.sh

UNLIMIT_RESOURCES=	datasize memorysize

SUBST_CLASSES+=			kdelibsfix
SUBST_STAGE.kdelibsfix=		pre-configure
SUBST_MESSAGE.kdelibsfix=	Fixing hardcoded paths.
SUBST_FILES.kdelibsfix= \
	kdecore/kstandarddirs.cpp \
	kdecore/ktimezones.cpp \
	kdeui/ksconfig.cpp \
	kio/kssl/kopenssl.cc
SUBST_SED.kdelibsfix=		-e 's:@LOCALBASE@:${LOCALBASE}:g'
SUBST_SED.kdelibsfix+=		-e 's:@PKGLOCALEDIR@:${PKGLOCALEDIR}:g'

SUBST_CLASSES+=		kdemagic
SUBST_STAGE.kdemagic=	pre-configure
SUBST_MESSAGE.kdemagic=	Add LOCALBASE paths to magic file.
SUBST_FILES.kdemagic=	kio/magic
SUBST_SED.kdemagic=	-n -e 'p' -e 's:/usr/local/bin:${LOCALBASE}/bin:p'

SPECIAL_PERMS+=	${PREFIX}/bin/fileshareset	${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/bin/kpac_dhcp_helper	${SETUID_ROOT_PERMS}

# ${SETUID_ROOT_PERMS} doesn't work here because the locate() method used to
# find the path to the kgrantpty expects it to have read permissions set.
SPECIAL_PERMS+=	${PREFIX}/bin/kgrantpty	${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 4555

.include "options.mk"

PLIST_VARS+=		kded
.if ${OPSYS} == "NetBSD"
.  if ${OS_VERSION:M1.5.[12]*} || ${OS_VERSION:M1.[0-4]*}
#			nothing
.  else
PLIST.kded=		yes
.  endif
# make sure zone.tab is installed
DEPENDS+=		zonetab-[0-9]*:../../time/zonetab
.else
PLIST.kded=		yes
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
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

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
CXXFLAGS:=	${CXXFLAGS:C/-O[0-9]*/-O/g}
CFLAGS:=	${CFLAGS:C/-O[0-9]*/-O/g}
CONFIGURE_ENV+= CXXFLAGS=${CXXFLAGS:M*:Q}
CONFIGURE_ENV+= CFLAGS=${CFLAGS:M*:Q}
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
