# $NetBSD: Makefile,v 1.21 2012/09/15 15:03:25 obache Exp $
#

DISTNAME=		mod_auth_mysql.c
PKGNAME=		${APACHE_PKG_PREFIX}-auth-mysql-1.11.12
PKGREVISION=		9
CATEGORIES=		www databases
MASTER_SITES=		ftp://ftp.kcilink.com/pub/
DISTFILES=		${DISTNAME}.gz mysql-group-auth.txt

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://ftp.kcilink.com/pub/
COMMENT=		Module to allow Apache 2 authentication against a MySQL database

CONFLICTS+=		ap-auth-mysql-[0-9]*

DIST_SUBDIR=		ap2-auth-mysql
EXTRACT_ONLY=		${DISTNAME}.gz

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
NO_CONFIGURE=		yes

PKG_DESTDIR_SUPPORT=	user-destdir

APACHE_MODULE_NAME=	mod_auth_mysql
DOC_DIR=		${PREFIX}/share/doc/${APACHE_MODULE_NAME}

PKG_APACHE_ACCEPTED=	apache2 apache22

INSTALLATION_DIRS+=	${DOC_DIR} lib/httpd

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
	    libexecdir=`${APXS} -q LIBEXECDIR` &&				\
	    ${APXS} -i -S LIBEXECDIR=${DESTDIR}"$${libexecdir}" 		\
	      -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_NAME}.la
	${INSTALL_DATA} ${WRKSRC}/mysql-group-auth.txt ${DESTDIR}${DOC_DIR}

.include "../../mk/apache.mk"
.include "../../mk/mysql.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
