# $NetBSD: Makefile,v 1.3 2000/06/22 14:28:52 jwise Exp $
#
# Note: we currently use the pre-built (-bin) distribution of Xalan-J,
# because although Xalan runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.

DISTNAME=	xalan-j_1_0_1
PKGNAME=	xalan-j-1.0.1
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/xalan-j/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://xml.apache.org/xalan-j/

DEPENDS+=	xerces-j-*:../../textproc/xerces-j

USE_JAVA=	yes
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

WRKSRC=		${WRKDIR}/xalan_1_0_1

do-install:
	${INSTALL_DATA} ${WRKSRC}/xalan.jar ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/bsf.jar ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/bsfengines.jar ${PREFIX}/lib/java
	${MKDIR} ${PREFIX}/share/doc/java/xalan
	cd ${WRKSRC}/docs ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/doc/java/xalan ; ${GTAR} pvxf - )
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/java/xalan
	${MKDIR} ${PREFIX}/share/examples/java/xalan
	cd ${WRKSRC}/samples ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/examples/java/xalan ; ${GTAR} pvxf - )
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/java/xalan

.include "../../mk/bsd.pkg.mk"
