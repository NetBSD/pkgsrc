# $NetBSD: Makefile,v 1.1.1.1 2004/07/16 11:28:19 jdolecek Exp $
#

DISTNAME=		libapache-mod-auth-mysql_4.3.1
PKGNAME=		${DISTNAME:S/libapache-mod/ap/:S/_/-/}
WRKSRC=			${WRKDIR}/${DISTNAME:S/_/-/}
CATEGORIES=		www databases security
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/liba/libapache-mod-auth-mysql/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://packages.debian.org/unstable/web/libapache-mod-auth-mysql.html
COMMENT=		Apache module to allow authentication against a MySQL database

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/include/mysql	\
			--with-mysql-libs=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mysql-client}/include/mysql
LDFLAGS+=		-lmysqlclient -L${BUILDLINK_PREFIX.mysql-client}/lib/mysql		\
			-Wl,${RPATH_FLAG} -Wl,${BUILDLINK_PREFIX.mysql-client}/lib/mysql

APACHE_MODULE_NAME=	mod_auth_mysql.so

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_mysql
	${INSTALL_DATA} ${WRKSRC}/DIRECTIVES ${PREFIX}/share/doc/mod_auth_mysql
	${INSTALL_DATA} ${WRKSRC}/USAGE ${PREFIX}/share/doc/mod_auth_mysql

.include "../../databases/mysql-client/buildlink3.mk"
.include "../../www/apache/module.mk"

.include "../../mk/bsd.pkg.mk"
