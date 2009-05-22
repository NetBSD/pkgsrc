# $NetBSD: Makefile,v 1.37 2009/05/22 17:59:41 zafer Exp $
#

DISTNAME=	xerces-c-src_2_8_0
PKGNAME=	${DISTNAME:S/-src_/-/:S/_/./g}
CATEGORIES=	textproc
MASTER_SITES=	http://www.apache.org/dist/xerces/c/2/sources/ \
				http://apache.speedbone.de/xerces/c/2/sources/ \
				ftp://ftp.riken.jp/net/apache/xerces/c/2/sources/
				
				

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xerces.apache.org/xerces-c/
COMMENT=	Validating C++ XML parser with DOM and SAX support

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/src/xercesc
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
XERCES_PLATFORM=	solaris
.elif ${OPSYS} == "Darwin"
XERCES_PLATFORM=	macosx
.else
XERCES_PLATFORM=	${LOWER_OPSYS}
.endif
XERCES_ENV+=		XERCESCROOT="${WRKDIR}/${DISTNAME}"

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./runConfigure
CONFIGURE_ARGS+=	-P ${PREFIX}		# installation prefix
CONFIGURE_ARGS+=	-p ${XERCES_PLATFORM}	# platform
CONFIGURE_ARGS+=	-n socket		# net accessor
CONFIGURE_ARGS+=	-m inmem		# message loader
CONFIGURE_ARGS+=	-r none			# threading
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}

PLIST_VARS+=		gnu-iconv native-iconv

CONFIGURE_ARGS.gnu-iconv+=	-t IconvGNU	# transcoder

CONFIGURE_ARGS.native-iconv+=	-t native	# transcoder

CONFIGURE_ENV+=		${XERCES_ENV}
MAKE_ENV+=		${XERCES_ENV}

# On Darwin, we have to use native (not libiconv) converter. see MacOSPlatformUtils.cpp.
.if ${OPSYS} == "Darwin"
ICONV_TYPE=		native
CFLAGS.Darwin+=		-DXML_USE_MACOS_UNICODECONVERTER -I${WRKDIR}/${DISTNAME}/src
.else
.include "../../converters/libiconv/buildlink3.mk"
.endif

post-extract:
	${MKDIR} ${WRKSRC}/util/Platforms/DragonFly
	${CP} ${WRKSRC}/util/Platforms/NetBSD/NetBSDPlatformUtils.cpp ${WRKSRC}/util/Platforms/DragonFly/DragonFlyPlatformUtils.cpp

pre-configure:
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/dom/impl/*.hpp \
		${DESTDIR}${PREFIX}/include/xercesc/dom/impl

.include "../../mk/bsd.pkg.mk"

# Must be after bsd.pkg.mk
PLIST.${ICONV_TYPE}-iconv=	yes
