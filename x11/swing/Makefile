# $NetBSD: Makefile,v 1.25 2005/06/17 03:50:44 jlam Exp $

DISTNAME=	swing1_1_1
PKGNAME=	swing-1.1.1
PKGREVISION=	1
CATEGORIES=	devel x11 java
MASTER_SITES=	# empty
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.javasoft.com/products/jfc/
DOWNLOAD=	http://java.sun.com/products/jfc/download.archive.html
COMMENT=	Sun's Java Foundation Classes (the Swing UI toolkit), version 1.1.1

RESTRICTED=	"Read license before redistributing the Java(tm) Foundation Classes"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

LICENSE=	sun-swing-license

WRKSRC=		${WRKDIR}/swing-1.1.1fcs
USE_JAVA=	run
NO_CONFIGURE=	yes
NO_BUILD=	yes

_FETCH_MESSAGE= \
	${ECHO} "======================================================================"; \
	${ECHO} ; \
	${ECHO} " The file ${DISTNAME}${EXTRACT_SUFX} containing the"; \
	${ECHO} " Java(tm) Foundation Classes must be fetched into:"; \
	${ECHO} ""; \
	${ECHO} "	${DISTDIR}"; \
	${ECHO} " from:"; \
	${ECHO} "	${DOWNLOAD}"; \
	${ECHO} ; \
	${ECHO} "======================================================================"

SWINGDIR=	${PREFIX}/lib/java/swing
EGDIR=		${PREFIX}/share/examples/swing
HTMLDIR=	${PREFIX}/share/doc/html/swing

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${SWINGDIR}
	${INSTALL_DATA} ${WRKSRC}/swingall.jar ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/beaninfo.jar ${SWINGDIR}
	${INSTALL_DATA} ${WRKSRC}/mac.jar ${SWINGDIR}
	${INSTALL_DATA} ${WRKSRC}/motif.jar ${SWINGDIR}
	${INSTALL_DATA} ${WRKSRC}/multi.jar ${SWINGDIR}
	${INSTALL_DATA} ${WRKSRC}/swing.jar ${SWINGDIR}
	${INSTALL_DATA} ${WRKSRC}/windows.jar ${SWINGDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc && ${PAX} -rw . ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${HTMLDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/examples && ${PAX} -rw . ${EGDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
