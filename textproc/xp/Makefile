# $NetBSD: Makefile,v 1.20 2006/09/18 12:14:53 joerg Exp $
#

DISTNAME=	xp
PKGNAME=	XP-0.5
PKGREVISION=	1
CATEGORIES=	textproc www java
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.jclark.com/xml/
COMMENT=	James Clark's non-validating XML Parser for Java

USE_TOOLS+=	unzip
EXTRACT_ONLY=	# empty
USE_JAVA=	run
NO_CONFIGURE=	yes
NO_BUILD=	yes

post-extract:
	cd ${WRKDIR} && unzip -x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${RM} -r ${WRKDIR}/docs/api/CVS ${WRKDIR}/docs/api/images/CVS

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKDIR}/xp.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/xp
	cd ${WRKDIR}/docs && ${PAX} -rw -pp . ${PREFIX}/share/doc/java/xp

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
