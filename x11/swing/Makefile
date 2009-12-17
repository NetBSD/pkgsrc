# $NetBSD: Makefile,v 1.34 2009/12/17 18:23:14 abs Exp $

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

PKG_DESTDIR_SUPPORT= user-destdir
INSTALLATION_DIRS+=lib/java/swing share/examples/swing share/doc/swing

do-install:
	${INSTALL_DATA} ${WRKSRC}/swingall.jar ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/beaninfo.jar ${DESTDIR}${SWINGDIR}
	${INSTALL_DATA} ${WRKSRC}/mac.jar ${DESTDIR}${SWINGDIR}
	${INSTALL_DATA} ${WRKSRC}/motif.jar ${DESTDIR}${SWINGDIR}
	${INSTALL_DATA} ${WRKSRC}/multi.jar ${DESTDIR}${SWINGDIR}
	${INSTALL_DATA} ${WRKSRC}/swing.jar ${DESTDIR}${SWINGDIR}
	${INSTALL_DATA} ${WRKSRC}/windows.jar ${DESTDIR}${SWINGDIR}
	cd ${WRKSRC}/doc && pax -rw . ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/examples && pax -rw . ${DESTDIR}${EGDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
