# $NetBSD: Makefile,v 1.6 2004/10/03 00:18:24 tv Exp $
#

DISTNAME=		libapache-mod-auth-mysql_4.3.1
PKGNAME=		${DISTNAME:S/libapache-mod/ap/:S/_/-/}
PKGREVISION=	1
WRKSRC=			${WRKDIR}/${DISTNAME:S/_/-/}
CATEGORIES=		www databases security
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/liba/libapache-mod-auth-mysql/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://packages.debian.org/unstable/web/libapache-mod-auth-mysql.html
COMMENT=		Apache (${PKG_APACHE}) module to allow authentication against a MySQL database

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/include/mysql	\
			--with-mysql-libs=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mysql-client}/include/mysql
LDFLAGS+=		-L${BUILDLINK_PREFIX.mysql-client}/lib/mysql	\
			-lmysqlclient					\
			${COMPILER_RPATH_FLAG}${PREFIX}/lib/mysql

APACHE_MODULE=		YES
APACHE_MODULE_NAME=	mod_auth_mysql.so

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_mysql
	${INSTALL_DATA} ${WRKSRC}/DIRECTIVES ${PREFIX}/share/doc/mod_auth_mysql
	${INSTALL_DATA} ${WRKSRC}/USAGE ${PREFIX}/share/doc/mod_auth_mysql

.include "../../databases/mysql-client/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
