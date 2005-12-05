# $NetBSD: Makefile,v 1.21 2005/12/05 20:51:08 rillig Exp $
#
# Note: we currently use the pre-built (-bin) distribution of Xalan-J,
# because although Xalan runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.

DISTNAME=	xalan-j_1_2
PKGNAME=	xalan-j-1.2
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/xalan-j/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://xml.apache.org/xalan-j/
COMMENT=	The Apache Project's XSLT implementation

DEPENDS+=	xerces-j>=1.2.0:../../textproc/xerces-j

WRKSRC=		${WRKDIR}
USE_JAVA=	run
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/xalan.jar ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/bsf.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/xalan
	cd ${WRKSRC}/docs && ${PAX} -rw -pp . ${PREFIX}/share/doc/java/xalan
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/xalan
	cd ${WRKSRC}/samples && ${PAX} -rw -pp . ${PREFIX}/share/examples/java/xalan

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
