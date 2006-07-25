# $NetBSD: Makefile,v 1.12 2006/07/25 07:37:30 martti Exp $

DISTNAME=		JAlbum6.5
PKGNAME=		jalbum-6.5.1
#PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://www.jalbum.net/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.jalbum.net/
COMMENT=		Web photo album generator

DIST_SUBDIR=		${PKGNAME_NOREV}
USE_JAVA=		run
PKG_JVMS_ACCEPTED=	blackdown-jdk13 kaffe sun-jdk13 sun-jdk14 sun-jdk15

WRKSRC=			${WRKDIR}/JAlbum

do-build:
	${SED}	-e s#@PKG_JAVA_HOME@#${PKG_JAVA_HOME:Q}#g	\
		-e s#@PREFIX@#${PREFIX:Q}#g			\
		< ${FILESDIR:Q}/jalbum > ${WRKDIR:Q}/jalbum

do-install:
	${INSTALL_SCRIPT} ${WRKDIR:Q}/jalbum ${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/jalbum
	(cd ${WRKDIR:Q}/JAlbum && ${PAX} -rw * ${PREFIX:Q}/share/jalbum)

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
