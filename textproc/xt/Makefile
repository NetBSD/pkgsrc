# $NetBSD: Makefile,v 1.23 2012/10/25 06:57:09 asau Exp $
#

DISTNAME=	xt
PKGNAME=	XT-19991105
PKGREVISION=	1
CATEGORIES=	textproc www
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jclark.com/xml/
COMMENT=	James Clark's Java implementation of XSLT

DEPENDS+=	XP-[0-9]*:../../textproc/xp

USE_JAVA=	run
USE_TOOLS+=	unzip pax
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	lib/java share/doc/java/xt share/examples/java/xt

do-install:
	${INSTALL_DATA} ${WRKDIR}/xt.jar ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} -c ${WRKDIR}/sax.jar ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} -c ${WRKDIR}/copying.txt ${DESTDIR}${PREFIX}/share/doc/java/xt
	${INSTALL_DATA} -c ${WRKDIR}/xt.htm ${DESTDIR}${PREFIX}/share/doc/java/xt
	cd ${WRKDIR}/demo && pax -rw -pp . ${DESTDIR}${PREFIX}/share/examples/java/xt

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
