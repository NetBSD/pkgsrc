# $NetBSD: Makefile,v 1.25 2005/05/16 01:15:34 jlam Exp $
# STOP!  Don't update this to a later version of this software.
# The JSDK and Apache Jakarta projects have merged, making the
# jakarta-tomcat package the current version of this software.
# This version exists in pkgsrc strictly to support Apache's
# mod_jserv, which will not build with newer (or older) versions.

DISTNAME=	jsdk20-solaris2-sparc
PKGNAME=	jsdk-2.0
CATEGORIES=	www java
MASTER_SITES=	# none
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://java.sun.com/products/servlet/index.html
COMMENT=	Sun's Java Servlet Development Kit, version 2.0

ARCHIVE=	http://java.sun.com/products/servlet/archive.html

LICENSE=	sun-jsdk20-license
USE_JAVA=	run

WRKSRC=		${WRKDIR}/JSDK2.0
BUILD_DEFS+=    JSDK_HOME
NO_CONFIGURE=
NO_BUILD=

PKGSRC_USE_TOOLS+=	gtar

RESTRICTED=		"Read license before redistributing the Java(tm) Servlet Development Kit"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

_FETCH_MESSAGE= 							\
	${ECHO} "======================================================================"; \
	${ECHO} ; 							\
	${ECHO} " The file ${DISTNAME}${EXTRACT_SUFX} containing"; 	\
	${ECHO} " ${COMMENT} must be fetched"; 				\
	${ECHO} " into:"; 						\
	${ECHO} "	${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}"; 	\
	${ECHO} " from:"; 						\
	${ECHO} "	${ARCHIVE}";                                    \
	${ECHO} ; 							\
	${ECHO} "======================================================================"

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/lib/jsdk.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/jsdk20
	cd ${WRKSRC}/doc ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/doc/java/jsdk20 ; ${GTAR} pvxf - )
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/java/jsdk20
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/README ${PREFIX}/share/doc/java/jsdk20
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/jsdk20
	cd ${WRKSRC}/examples ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/examples/java/jsdk20 ; ${GTAR} pvxf - )
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/java/jsdk20

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
