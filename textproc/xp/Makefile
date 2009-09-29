# $NetBSD: Makefile,v 1.24 2009/09/29 16:58:49 wiz Exp $
#

DISTNAME=	xp
PKGNAME=	XP-0.5
PKGREVISION=	1
CATEGORIES=	textproc www java
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jclark.com/xml/
COMMENT=	James Clark's non-validating XML Parser for Java

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax unzip
EXTRACT_ONLY=	# empty
USE_JAVA=	run
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	lib/java share/doc/java/xp

post-extract:
	cd ${WRKDIR} && unzip ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${RM} -r ${WRKDIR}/docs/api/CVS ${WRKDIR}/docs/api/images/CVS

do-install:
	${INSTALL_DATA} ${WRKDIR}/xp.jar ${DESTDIR}${PREFIX}/lib/java
	cd ${WRKDIR}/docs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/java/xp

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
