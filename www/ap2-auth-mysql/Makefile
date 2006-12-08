# $NetBSD: Makefile,v 1.15 2006/12/08 23:34:10 xtraeme Exp $
#

DISTNAME=		mod_auth_mysql.c
PKGNAME=		ap2-auth-mysql-1.11.12
PKGREVISION=		6
CATEGORIES=		www databases
MASTER_SITES=		ftp://ftp.kcilink.com/pub/
DISTFILES=		${DISTNAME}.gz mysql-group-auth.txt

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		ftp://ftp.kcilink.com/pub/
COMMENT=		Module to allow Apache 2 authentication against a MySQL database

CONFLICTS+=		ap-auth-mysql-*

DIST_SUBDIR=		ap2-auth-mysql
EXTRACT_ONLY=		${DISTNAME}.gz

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
NO_CONFIGURE=		yes

APACHE_MODULE_NAME=	mod_auth_mysql
DOC_DIR=		${PREFIX}/share/doc/${APACHE_MODULE_NAME}

PKG_APACHE_ACCEPTED=	apache2 apache22

post-extract:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/${DISTNAME} ${WRKSRC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/mysql-group-auth.txt ${WRKSRC}

do-build:
	cd ${WRKSRC} &&								\
	${APXS} -c -n ${APACHE_MODULE_NAME}					\
	    -I${BUILDLINK_PREFIX.mysql-client}/include				\
	    -L${BUILDLINK_PREFIX.mysql-client}/lib/mysql			\
	    ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib/mysql	\
	    -lmysqlclient ${DISTNAME}

do-install:
	cd ${WRKSRC} &&								\
	${APXS} -i -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_NAME}.la
	${INSTALL_DATA_DIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/mysql-group-auth.txt ${DOC_DIR}

.include "../../mk/apache.mk"
.include "../../mk/mysql.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
