# $NetBSD: Makefile,v 1.5 2001/09/27 23:18:47 jlam Exp $
#

DISTNAME=	xp
PKGNAME=	XP-0.5
CATEGORIES=	textproc www
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.jclark.com/xml/
COMMENT=	James Clark's non-validating XML Parser for Java

DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

EXTRACT_ONLY=
USE_JAVA=	yes
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

post-extract:
	cd ${WRKDIR} && ${LOCALBASE}/bin/unzip -x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${RM} -r ${WRKDIR}/docs/api/CVS ${WRKDIR}/docs/api/images/CVS

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKDIR}/xp.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/xp
	cd ${WRKDIR}/docs ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/doc/java/xp ; ${GTAR} pvxf - )
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/java/xp

.include "../../mk/bsd.pkg.mk"
