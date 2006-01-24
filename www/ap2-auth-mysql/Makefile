# $NetBSD: Makefile,v 1.12 2006/01/24 07:32:43 wiz Exp $
#

DISTNAME=		mod_auth_mysql.c
PKGNAME=		ap2-auth-mysql-1.11.12
PKGREVISION=		5
CATEGORIES=		www databases
MASTER_SITES=		ftp://ftp.kcilink.com/pub/
DISTFILES=		${DISTNAME}.gz mysql-group-auth.txt

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		ftp://ftp.redhat.com/pub/redhat/linux/9/en/os/i386/SRPMS/
COMMENT=		Module to allow Apache 2 authentication against a MySQL database

CONFLICTS+=		ap-auth-mysql-*

DIST_SUBDIR=		ap2-auth-mysql
EXTRACT_ONLY=		${DISTNAME}.gz

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
NO_CONFIGURE=		yes

APACHE_MODULE_NAME=	mod_auth_mysql
DOC_DIR=		${PREFIX}/share/doc/${APACHE_MODULE_NAME}

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

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
