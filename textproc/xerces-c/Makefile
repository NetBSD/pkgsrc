# $NetBSD: Makefile,v 1.5 2002/10/30 09:46:42 seb Exp $
#

DISTNAME=	xerces-c-src1_3_0
PKGNAME=	xerces-c-1.3.0
CATEGORIES=	textproc
MASTER_SITES=	http://xml.apache.org/dist/xerces-c/stable/

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://xml.apache.org/xerces-c/
COMMENT=	The Apache Project's validating XML parser with DOM and SAX support

WRKSRC=		${WRKDIR}/xerces-c-src1_3_0/src/
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_BUILDLINK2=	YES

ICUROOT=	${BUILDLINK_PREFIX.icu}

SCRIPT_ENV+=	ICUROOT="${BUILDLINK_PREFIX.icu}"

FLAGS+=		-O2 -I${ICUROOT}/include \
		-DXML_USE_ICU_TRANSCODER \
		-DXML_USE_NETACCESSOR_SOCKET \
		-DAPP_NO_THREADS

CFLAGS+=	${FLAGS}
CXXFLAGS+=	${FLAGS}
LIBS=		-L${ICUROOT}/lib -Wl,-R${ICUROOT}/lib
LIBS+=		-L${ICUROOT}/lib/icu/current -Wl,-R${ICUROOT}/lib/icu/current

CONFIGURE_ENV+=	XERCESCROOT="${WRKDIR}/xerces-c-src1_3_0" \
		ICUROOT=${ICUROOT} \
		NETACCESSOR=Socket \
		TRANSCODER=ICU

MAKE_ENV+=	XERCESCROOT="${WRKDIR}/xerces-c-src1_3_0" \
		ICUROOT="${BUILDLINK_PREFIX.icu}" \
		NETACCESSOR=Socket \
		TRANSCODER=ICU \

post-extract:
	${MKDIR} ${WRKSRC}/util/Platforms/NetBSD
	${CP} \
		${FILESDIR}/Makefile.in \
		${FILESDIR}/NetBSDDefs.hpp \
		${FILESDIR}/NetBSDPlatformUtils.cpp \
		${WRKSRC}/util/Platforms/NetBSD

pre-configure:
	${CHMOD} a+x ${WRKSRC}/configure

.include "../../textproc/icu/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
