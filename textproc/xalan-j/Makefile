# $NetBSD: Makefile,v 1.25 2010/02/12 20:46:14 joerg Exp $
#
# Note: we currently use the pre-built (-bin) distribution of Xalan-J,
# because although Xalan runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.

DISTNAME=	xalan-j_1_2
PKGNAME=	xalan-j-1.2
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/xalan-j/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xml.apache.org/xalan-j/
COMMENT=	The Apache Project's XSLT implementation

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	xerces-j>=1.2.0:../../textproc/xerces-j

WRKSRC=		${WRKDIR}
USE_JAVA=	run
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	lib/java share/doc/java/xalan share/examples/java/xalan

do-install:
	${INSTALL_DATA} ${WRKSRC}/xalan.jar ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/bsf.jar ${DESTDIR}${PREFIX}/lib/java
	cd ${WRKSRC}/docs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/java/xalan
	cd ${WRKSRC}/samples && pax -rw -pp . ${DESTDIR}${PREFIX}/share/examples/java/xalan

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
