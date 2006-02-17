# $NetBSD: Makefile,v 1.7 2006/02/17 08:01:31 martti Exp $

DISTNAME=		JAlbum6.2
PKGNAME=		jalbum-6.2
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://www.jalbum.net/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.jalbum.net/
COMMENT=		Web photo album generator

DIST_SUBDIR=		${PKGNAME_NOREV}
USE_JAVA=		run
PKG_JVMS_ACCEPTED=	blackdown-jdk13 kaffe sun-jdk13 sun-jdk14 sun-jdk15

WRKSRC=			${WRKDIR:Q}/JAlbum

do-build:
	${SED}	-e "s#@PKG_JAVA_HOME@#${PKG_JAVA_HOME:Q}#g"	\
		-e "s#@PREFIX@#${PREFIX:Q}#g"			\
		< ${FILESDIR:Q}/jalbum > ${WRKDIR:Q}/jalbum

do-install:
	${INSTALL_SCRIPT} ${WRKDIR:Q}/jalbum ${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/jalbum
	(cd ${WRKDIR:Q}/JAlbum && ${PAX} -rw * ${PREFIX:Q}/share/jalbum)

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
