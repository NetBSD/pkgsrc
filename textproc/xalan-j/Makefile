# $NetBSD: Makefile,v 1.1.1.1 2000/05/30 16:14:33 jwise Exp $
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
	${INSTALL} -c ${WRKSRC}/xalan.jar ${PREFIX}/lib/java
	${INSTALL} -c ${WRKSRC}/bsf.jar ${PREFIX}/lib/java
	${INSTALL} -c ${WRKSRC}/bsfengines.jar ${PREFIX}/lib/java
	${MKDIR} ${PREFIX}/share/doc/java/xalan
	cd ${WRKSRC}/docs ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/doc/java/xalan ; ${GTAR} pvxf - )
	${MKDIR} ${PREFIX}/share/examples/java/xalan
	cd ${WRKSRC}/samples ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/examples/java/xalan ; ${GTAR} pvxf - )

.include "../../mk/bsd.pkg.mk"
