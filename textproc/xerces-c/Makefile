# $NetBSD: Makefile,v 1.22 2004/10/03 00:18:21 tv Exp $
#

DISTNAME=	xerces-c-src_2_3_0
PKGNAME=	${DISTNAME:S/-src_/-/:S/_/./g}
PKGREVISION=	2
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
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}

CONFIGURE_ARGS.gnu-iconv=	-t IconvGNU	# transcoder
PLIST_SUBST.gnu-iconv=		NATIVEICONV="@comment " GNUICONV=""

CONFIGURE_ARGS.native-iconv=	-t native	# transcoder
PLIST_SUBST.native-iconv=	NATIVEICONV="" GNUICONV="@comment "

CONFIGURE_ENV+=		${XERCES_ENV}
MAKE_ENV+=		${XERCES_ENV}
PLIST_SUBST+=		${PLIST_SUBST.${ICONV_TYPE}-iconv}

.include "../../converters/libiconv/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/dom/impl/*.hpp \
		${PREFIX}/include/xercesc/dom/impl

.include "../../mk/bsd.pkg.mk"
