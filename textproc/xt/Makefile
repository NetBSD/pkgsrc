# $NetBSD: Makefile,v 1.1.1.1 2000/05/31 14:41:45 jwise Exp $
#

DISTNAME=	xt
PKGNAME=	XT-19991105
CATEGORIES=	textproc www
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.jclark.com/xml/

DEPENDS+=	unzip-*:../../archivers/unzip
DEPENDS+=	XP-*:../../textproc/xp

EXTRACT_ONLY=
USE_JAVA=	yes
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

post-extract:
	cd ${WRKDIR} && ${LOCALBASE}/bin/unzip -x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${MKDIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKDIR}/xt.jar ${PREFIX}/lib/java
	${INSTALL_DATA} -c ${WRKDIR}/sax.jar ${PREFIX}/lib/java
	${MKDIR} ${PREFIX}/share/doc/java/xt
	${INSTALL_DATA} -c ${WRKDIR}/copying.txt ${PREFIX}/share/doc/java/xt
	${INSTALL_DATA} -c ${WRKDIR}/xt.htm ${PREFIX}/share/doc/java/xt
	${MKDIR} ${PREFIX}/share/examples/java/xt
	cd ${WRKDIR}/demo ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/examples/java/xt ; ${GTAR} pvxf - )

.include "../../mk/bsd.pkg.mk"
