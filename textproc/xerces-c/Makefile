# $NetBSD: Makefile,v 1.15 2004/01/24 15:13:20 grant Exp $
#

DISTNAME=	xerces-c-src1_7_0
PKGNAME=	${DISTNAME:S/-src/-/:S/_/./g}
CATEGORIES=	textproc
MASTER_SITES=	http://xml.apache.org/dist/xerces-c/stable/archives/Xerces-C_${DISTNAME:S/xerces-c-src//}/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xml.apache.org/xerces-c/
COMMENT=	Validating C++ XML parser with DOM and SAX support

WRKSRC=			${WRKDIR}/${DISTNAME}/src/xercesc
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.prefs.mk"
.if ${LOWER_OPSYS} == "SunOS"
XERCES_PLATFORM=	solaris
.elif ${LOWER_OPSYS} == "Darwin"
XERCES_PLATFORM=	macosx
.else
XERCES_PLATFORM=	${LOWER_OPSYS}
.endif
XERCES_ENV+=		XERCESCROOT="${WRKDIR}/${DISTNAME}"
XERCES_ENV+=		ICUROOT="${BUILDLINK_PREFIX.icu}"

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./runConfigure
CONFIGURE_ARGS+=	-P ${PREFIX}		# installation prefix
CONFIGURE_ARGS+=	-p ${XERCES_PLATFORM}	# platform
CONFIGURE_ARGS+=	-n socket		# net accessor
CONFIGURE_ARGS+=	-m icu			# message loader
CONFIGURE_ARGS+=	-t icu			# transcoder
CONFIGURE_ARGS+=	-r none			# threading

CONFIGURE_ENV+=		${XERCES_ENV}
MAKE_ENV+=		${XERCES_ENV}

post-extract:
	${MKDIR} ${WRKSRC}/util/Platforms/NetBSD
	${CP}	${FILESDIR}/Makefile.in					\
		${FILESDIR}/NetBSDDefs.hpp				\
		${FILESDIR}/NetBSDPlatformUtils.cpp			\
		${WRKSRC}/util/Platforms/NetBSD

pre-configure:
	${CHMOD} +x ${WRKSRC}/${CONFIGURE_SCRIPT}

.include "../../textproc/icu/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
