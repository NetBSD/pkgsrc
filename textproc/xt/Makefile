# $NetBSD: Makefile,v 1.8 2002/07/29 22:23:29 jlam Exp $
#

DISTNAME=	xt
PKGNAME=	XT-19991105
CATEGORIES=	textproc www
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.jclark.com/xml/
COMMENT=	James Clark's Java implementation of XSLT

DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	XP-[0-9]*:../../textproc/xp

EXTRACT_ONLY=
USE_JAVA=	run
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

post-extract:
	cd ${WRKDIR} && ${LOCALBASE}/bin/unzip -x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKDIR}/xt.jar ${PREFIX}/lib/java
	${INSTALL_DATA} -c ${WRKDIR}/sax.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/xt
	${INSTALL_DATA} -c ${WRKDIR}/copying.txt ${PREFIX}/share/doc/java/xt
	${INSTALL_DATA} -c ${WRKDIR}/xt.htm ${PREFIX}/share/doc/java/xt
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/xt
	cd ${WRKDIR}/demo && ${PAX} -rwpp . ${PREFIX}/share/examples/java/xt

.include "../../mk/bsd.pkg.mk"
