# $NetBSD: Makefile,v 1.26 2009/12/16 20:02:01 martti Exp $

DISTNAME=		Jalbum${VERSION}
PKGNAME=		jalbum-${VERSION}
#PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://jalbum.net/download/
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_SUFX=		.zip

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://jalbum.net/
COMMENT=		Web photo album generator

LICENSE=		gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

VERSION=		8.5.3

USE_JAVA2=		1.5
PKG_JVMS_ACCEPTED=	sun-jdk15 sun-jdk6

WRKSRC=			${WRKDIR}/Jalbum

INSTALLATION_DIRS+=	bin ${PREFIX}/share/jalbum

USE_TOOLS+=		pax

post-extract:
	${ECHO} "===> Removing invalid skins"
	(cd ${WRKSRC} && rm -rf skins/Chameleon/styles/Black*)

do-build:
	sed	-e s#@PKG_JAVA_HOME@#${PKG_JAVA_HOME}#g		\
		-e s#@PREFIX@#${PREFIX}#g			\
		< ${FILESDIR}/jalbum > ${WRKDIR}/jalbum

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jalbum ${DESTDIR}${PREFIX}/bin
	cd ${WRKDIR}/Jalbum && pax -rw . ${DESTDIR}${PREFIX}/share/jalbum

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
