# $NetBSD: Makefile,v 1.1.1.1 2001/01/13 16:38:06 skrll Exp $
#

DISTNAME=	xerces-c-src1_3_0
PKGNAME=	xerces-c-1.3.0
CATEGORIES=	textproc
MASTER_SITES=	http://xml.apache.org/dist/xerces-c/stable/

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://xml.apache.org/xerces-c/

DEPENDS=	icu>=1.7:../../textproc/icu

WRKSRC=		${WRKDIR}/xerces-c-src1_3_0/src/
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

ICUROOT=	${PREFIX}

SCRIPT_ENV+=	ICUROOT="${LOCALBASE}"

FLAGS+=		-O2 -I${ICUROOT}/include \
		-DXML_USE_ICU_TRANSCODER \
		-DXML_USE_NETACCESSOR_SOCKET \
		-DAPP_NO_THREADS

CFLAGS+=	${FLAGS}
CXXFLAGS+=	${FLAGS}

CONFIGURE_ENV+=	XERCESCROOT="${WRKDIR}/xerces-c-src1_3_0" \
		ICUROOT=${ICUROOT} \
		NETACCESSOR=Socket \
		TRANSCODER=ICU \
		LIBS="-L${ICUROOT}/lib -Wl,-R${ICUROOT}/lib -L${ICUROOT}/lib/icu/current -Wl,-R${ICUROOT}/lib/icu/current"

MAKE_ENV+=	XERCESCROOT="${WRKDIR}/xerces-c-src1_3_0" \
		ICUROOT="${LOCALBASE}" \
		NETACCESSOR=Socket \
		TRANSCODER=ICU \
		CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}"

post-extract:
	${MKDIR} ${WRKSRC}/util/Platforms/NetBSD
	${CP} \
		${FILESDIR}/Makefile.in \
		${FILESDIR}/NetBSDDefs.hpp \
		${FILESDIR}/NetBSDPlatformUtils.cpp \
		${WRKSRC}/util/Platforms/NetBSD

pre-configure:
	${CHMOD} a+x ${WRKSRC}/configure

.include "../../mk/bsd.pkg.mk"
