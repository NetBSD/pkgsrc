# $NetBSD: Makefile,v 1.30 2012/10/25 06:57:07 asau Exp $
#
# Note: we currently use the pre-built (-bin) distribution of Xerces-J,
# because although Xerces runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.

DISTNAME=	Xerces-J-bin.1.2.0
PKGNAME=	xerces-j-1.2.0
PKGREVISION=	1
CATEGORIES=	textproc www
MASTER_SITES=	http://xerces.apache.org/dist/xerces-j/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xerces.apache.org/xerces-j/
COMMENT=	The Apache Project's validating XML parser with DOM and SAX support

WRKSRC=		${WRKDIR}/xerces-1_2_0
USE_JAVA=	run
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes

post-extract:
	chmod -R u+w,go-w ${WRKSRC}

INSTALLATION_DIRS=	lib/java share/doc/java/xerces share/examples/java/xerces

do-install:
	${INSTALL_DATA} ${WRKSRC}/xerces.jar ${DESTDIR}${PREFIX}/lib/java
	cd ${WRKSRC}/docs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/java/xerces
	${INSTALL_DATA} ${WRKSRC}/xercesSamples.jar ${DESTDIR}${PREFIX}/share/examples/java/xerces
	cd ${WRKSRC}/data && pax -rw -pp . ${DESTDIR}${PREFIX}/share/examples/java/xerces

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
