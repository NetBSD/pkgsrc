# $NetBSD: Makefile,v 1.1.1.1 2000/05/31 14:41:05 jwise Exp $
#

DISTNAME=	xp
PKGNAME=	XP-0.5
CATEGORIES=	textproc www
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.jclark.com/xml/

DEPENDS+=	unzip-*:../../archivers/unzip

EXTRACT_ONLY=
USE_JAVA=	yes
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

post-extract:
	cd ${WRKDIR} && ${LOCALBASE}/bin/unzip -x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${RM} -r ${WRKDIR}/docs/api/CVS ${WRKDIR}/docs/api/images/CVS

do-install:
	${MKDIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKDIR}/xp.jar ${PREFIX}/lib/java
	${MKDIR} ${PREFIX}/share/doc/java/xp
	cd ${WRKDIR}/docs ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/doc/java/xp ; ${GTAR} pvxf - )

.include "../../mk/bsd.pkg.mk"
