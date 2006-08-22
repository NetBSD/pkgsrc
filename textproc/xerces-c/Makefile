# $NetBSD: Makefile,v 1.30 2006/08/22 16:30:46 joerg Exp $
#

DISTNAME=	xerces-c-src_2_7_0
PKGNAME=	${DISTNAME:S/-src_/-/:S/_/./g}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://apache.rmplc.co.uk/xml/xerces-c/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xml.apache.org/xerces-c/
COMMENT=	Validating C++ XML parser with DOM and SAX support

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/src/xercesc
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

.include "../../mk/bsd.prefs.mk"
.if ${LOWER_OPSYS} == "SunOS"
XERCES_PLATFORM=	solaris
.elif ${LOWER_OPSYS} == "Darwin"
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

CONFIGURE_ARGS.gnu-iconv+=	-t IconvGNU	# transcoder
PLIST_SUBST.gnu-iconv+=		NATIVEICONV="@comment "
PLIST_SUBST.gnu-iconv+=		GNUICONV=""

CONFIGURE_ARGS.native-iconv+=	-t native	# transcoder
PLIST_SUBST.native-iconv+=	NATIVEICONV=""
PLIST_SUBST.native-iconv+=	GNUICONV="@comment "

CONFIGURE_ENV+=		${XERCES_ENV}
MAKE_ENV+=		${XERCES_ENV}
PLIST_SUBST+=		${PLIST_SUBST.${ICONV_TYPE}-iconv}

.include "../../converters/libiconv/buildlink3.mk"

post-extract:
	${MKDIR} ${WRKSRC}/util/Platforms/DragonFly
	${CP} ${WRKSRC}/util/Platforms/NetBSD/NetBSDPlatformUtils.cpp ${WRKSRC}/util/Platforms/DragonFly/DragonFlyPlatformUtils.cpp

pre-configure:
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/dom/impl/*.hpp \
		${PREFIX}/include/xercesc/dom/impl

.include "../../mk/bsd.pkg.mk"
