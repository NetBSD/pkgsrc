# $NetBSD: Makefile,v 1.8 2001/11/14 14:47:55 agc Exp $
#
# Note: we currently use the pre-built (-bin) distribution of Xalan-J,
# because although Xalan runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.

DISTNAME=	xalan-j_1_2
PKGNAME=	xalan-j-1.2
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/xalan-j/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://xml.apache.org/xalan-j/
COMMENT=	the Apache Project's XSLT implementation

DEPENDS+=	xerces-j>=1.2.0:../../textproc/xerces-j

USE_JAVA=	yes
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/xalan.jar ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/bsf.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/xalan
	cd ${WRKSRC}/docs && ${PAX} -rwpe . ${PREFIX}/share/doc/java/xalan
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/java/xalan
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/xalan
	cd ${WRKSRC}/samples && ${PAX} -rwpe . ${PREFIX}/share/examples/java/xalan
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/java/xalan

.include "../../mk/bsd.pkg.mk"
