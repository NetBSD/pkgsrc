# $NetBSD: Makefile,v 1.31 2014/06/15 06:37:54 obache Exp $
#

DISTNAME=	Xerces-J-bin.1.4.4
PKGNAME=	xerces-j-1.4.4
CATEGORIES=	textproc www
MASTER_SITES=	http://archive.apache.org/dist/xml/xerces-j/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xerces.apache.org/xerces-j/
COMMENT=	The Apache Project's validating XML parser with DOM and SAX support
LICENSE=	apache-1.1

WRKSRC=		${WRKDIR}/xerces-1_4_4
USE_JAVA=	run
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes

post-extract:
	chmod -R u+w,go-w ${WRKSRC}

INSTALLATION_DIRS=	lib/java share/doc/java/xerces share/examples/java/xerces

do-install:
	${INSTALL_DATA} ${WRKSRC}/xerces.jar ${DESTDIR}${PREFIX}/lib/java
	cd ${WRKSRC}/docs/html && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/java/xerces
	${INSTALL_DATA} ${WRKSRC}/xercesSamples.jar ${DESTDIR}${PREFIX}/share/examples/java/xerces
	cd ${WRKSRC}/data && pax -rw -pp . ${DESTDIR}${PREFIX}/share/examples/java/xerces

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
