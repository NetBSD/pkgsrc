# $NetBSD: Makefile,v 1.19 2004/02/18 20:30:31 minskim Exp $
#

DISTNAME=	xerces-c-src_2_3_0
PKGNAME=	${DISTNAME:S/-src_/-/:S/_/./g}
CATEGORIES=	textproc
MASTER_SITES=	http://xml.apache.org/dist/xerces-c/stable/archives/Xerces-C_2_3_0/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xml.apache.org/xerces-c/
COMMENT=	Validating C++ XML parser with DOM and SAX support

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/src/xercesc
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
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

.include "../../converters/libiconv/buildlink3.mk"

.if defined(ICONV_TYPE) && (${ICONV_TYPE} == "gnu")
CONFIGURE_ARGS+=	-t IconvGNU		# transcoder
PLIST_SUBST+=		NATIVEICONV="@comment " GNUICONV=""
.else
CONFIGURE_ARGS+=	-t native		# transcoder
PLIST_SUBST+=		NATIVEICONV="" GNUICONV="@comment "
.endif

CONFIGURE_ENV+=		${XERCES_ENV}
MAKE_ENV+=		${XERCES_ENV}

post-install:
	${INSTALL_DATA} ${WRKSRC}/dom/impl/*.hpp \
		${PREFIX}/include/xercesc/dom/impl

.include "../../mk/bsd.pkg.mk"
