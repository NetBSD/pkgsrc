# $NetBSD: Makefile,v 1.33 2009/05/19 08:59:39 wiz Exp $

DISTNAME=	swing1_1_1
PKGNAME=	swing-1.1.1
PKGREVISION=	3
CATEGORIES=	devel x11 java
MASTER_SITES=	# empty
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://java.sun.com/products/jfc/
COMMENT=	Sun's Java Foundation Classes (the Swing UI toolkit), version 1.1.1
LICENSE=	sun-swing-license

RESTRICTED=	Read license before redistributing the Java(tm) Foundation Classes
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DOWNLOAD=	http://java.sun.com/products/jfc/download.archive.html

WRKSRC=		${WRKDIR}/swing-1.1.1fcs
USE_JAVA=	run
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes

FETCH_MESSAGE=	" The file ${DISTNAME}${EXTRACT_SUFX} containing the"
FETCH_MESSAGE+=	" Java(tm) Foundation Classes must be fetched into:"
FETCH_MESSAGE+=	""
FETCH_MESSAGE+=	"	${DISTDIR}"
FETCH_MESSAGE+= " from:"
FETCH_MESSAGE+= "	${DOWNLOAD}"

SWINGDIR=	${PREFIX}/lib/java/swing
EGDIR=		${PREFIX}/share/examples/swing
HTMLDIR=	${PREFIX}/share/doc/swing

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
	cd ${WRKSRC}/doc && pax -rw . ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${HTMLDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/examples && pax -rw . ${EGDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
