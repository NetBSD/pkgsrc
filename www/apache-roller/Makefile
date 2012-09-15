# $NetBSD: Makefile,v 1.6 2012/09/15 15:03:26 obache Exp $
#

DISTNAME=	apache-roller-${ROLLER_VER}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE:=roller/roller-4/v${ROLLER_VER}/bin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://roller.apache.org/
COMMENT=	Full-featured, multi-user and group-blog server

BUILD_DEPENDS+=	fastjar-[0-9]*:../../archivers/fastjar

USE_JAVA=	run
USE_JAVA2=	1.5
ROLLER_VER=	4.0.1

PKG_DESTDIR_SUPPORT=	user-destdir
PLIST_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV:Q}

.include "options.mk"

do-build:
	cd ${WRKSRC}/webapp && ${PREFIX}/bin/fastjar \
		cf ${PKGNAME_NOREV}.war -C roller/ .

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/apache-roller
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/apache-roller
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/apache-roller

	${INSTALL_DATA} ${WRKSRC}/docs/roller-*.pdf \
		${DESTDIR}${PREFIX}/share/doc/apache-roller
	${INSTALL_DATA} ${WRKSRC}/*.txt \
		${DESTDIR}${PREFIX}/share/doc/apache-roller
	${INSTALL_DATA} ${WRKSRC}/webapp/${PKGNAME_NOREV}.war \
		${DESTDIR}${PREFIX}/share/apache-roller
	${INSTALL_DATA} ${FILESDIR}/roller-custom.properties \
		${DESTDIR}${PREFIX}/share/examples/apache-roller

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
