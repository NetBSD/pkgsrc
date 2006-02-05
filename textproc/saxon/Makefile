# $NetBSD: Makefile,v 1.15 2006/02/05 23:11:07 joerg Exp $
#

DISTNAME=	saxon
PKGNAME=	saxon-6.0.2
PKGREVISION=	1
CATEGORIES=	textproc www
MASTER_SITES=	${HOMEPAGE}saxon6.0.2/
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://users.iclway.co.uk/mhkay/saxon/
COMMENT=	Michael H. Kay's Java XSLT processor

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
USE_JAVA=	run
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/saxon.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java
	cd ${WRKSRC} && ${PAX} -rw -s '/^doc/saxon/' doc ${PREFIX}/share/doc/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/saxon
	cd ${WRKSRC} && ${PAX} -rw -s '/^samples/saxon/' samples ${PREFIX}/share/examples/java

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
