# $NetBSD: Makefile,v 1.11 2002/12/26 20:52:13 jlam Exp $
#

DISTNAME=	xp
PKGNAME=	XP-0.5
CATEGORIES=	textproc www
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.jclark.com/xml/
COMMENT=	James Clark's non-validating XML Parser for Java

EXTRACT_ONLY=	# empty
USE_JAVA=	run
USE_BUILDLINK2=
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
	cd ${WRKDIR}/docs && ${PAX} -rwpp . ${PREFIX}/share/doc/java/xp

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
