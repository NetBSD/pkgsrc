# $NetBSD: Makefile,v 1.16 2006/05/16 02:35:37 ben Exp $
#

DISTNAME=		libapache-mod-auth-mysql_4.3.1
PKGNAME=		${DISTNAME:S/libapache-mod/ap/:S/_/-/}
PKGREVISION=		5
WRKSRC=			${WRKDIR}/${DISTNAME:S/_/-/}
CATEGORIES=		www databases security
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/liba/libapache-mod-auth-mysql/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://packages.debian.org/unstable/web/libapache-mod-auth-mysql.html
COMMENT=		Module to allow apache authentication against a MySQL database

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/include/mysql	\
			--with-mysql-libs=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/mysql

.include "../../mk/apache.mk"

.if ${PKG_APACHE} == "apache13"
CONFIGURE_ARGS+=	--enable-apache13 --disable-apache2
.else
CONFIGURE_ARGS+=	--disable-apache13 --enable-apache2
.endif

APACHE_MODULE=		YES
APACHE_MODULE_NAME=	mod_auth_mysql.so

do-install:
	if [ -f ${WRKSRC}/.libs/${PKG_APACHE}_mod_auth_mysql.so ]; then	\
		${INSTALL_DATA} \
			${WRKSRC}/.libs/${PKG_APACHE}_mod_auth_mysql.so \
			${PREFIX}/lib/httpd/mod_auth_mysql.so;   \
	elif [ -f ${WRKSRC}/libs/${PKG_APACHE}_mod_auth_mysql.so ]; then \
		${INSTALL_DATA} \
			${WRKSRC}/libs/${PKG_APACHE}_mod_auth_mysql.so  \
			${PREFIX}/lib/httpd/mod_auth_mysql.so;   \
	elif [ -f ${WRKSRC}/${PKG_APACHE}_mod_auth_mysql.so ]; then \
		${INSTALL_DATA} \
			${WRKSRC}/${PKG_APACHE}_mod_auth_mysql.so  \
			${PREFIX}/lib/httpd/mod_auth_mysql.so;   \
	fi
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_mysql
	${INSTALL_DATA} ${WRKSRC}/DIRECTIVES ${PREFIX}/share/doc/mod_auth_mysql
	${INSTALL_DATA} ${WRKSRC}/USAGE ${PREFIX}/share/doc/mod_auth_mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
