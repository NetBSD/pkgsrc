# $NetBSD: Makefile,v 1.1.1.1 2001/01/15 12:42:09 skrll Exp $
#

DISTNAME=	Xalan-C_1_0-linux
PKGNAME=	xalan-c-1.0
CATEGORIES=	textproc
MASTER_SITES=	http://xml.apache.org/dist/xalan-c/

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://xml.apache.org/xalan-c/

DEPENDS+=	icu>=1.7:../../textproc/icu
DEPENDS+=	xerces-c>=1.3.0:../../textproc/xerces-c

WRKSRC=		${WRKDIR}/xml-xalan/c/src
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

#MAN1=		testXSLT.1

MAKE_ENV+=	XALANCROOT="${WRKDIR}/xml-xalan" \
		XERCESCROOT="${PREFIX}" \
		XALAN_USE_ICU="yes"

pre-configure:
	${CHMOD} a+rx ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/xml-xalan/lib/libxalan-c1_0.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKDIR}/xml-xalan/bin/testXPath ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/xml-xalan/bin/testXSLT ${PREFIX}/bin
	cd ${WRKSRC}; \
	XMLDIRS="DOMSupport ICUBridge Include XercesParserLiaison PlatformSupport TestXPath XMLSupport XPath XSLT XalanDOM"; \
	for i in $${XMLDIRS}; do \
	    ${ECHO} creating ${PREFIX}/include/$${i}; \
	    ${INSTALL_DATA_DIR} ${PREFIX}/include/$${i}; \
	done; \
	for i in `find $${XMLDIRS} -type f -name "*.hpp"`; do \
	    ${ECHO} installing ${PREFIX}/include/$${i}; \
	    ${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/include/$${i}; \
	done
	${INSTALL_MAN} ${FILESDIR}/testXSLT.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
