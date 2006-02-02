# $NetBSD: Makefile,v 1.11 2006/02/02 05:00:02 ben Exp $
#

DISTNAME=		libapache-mod-auth-mysql_4.3.1
PKGNAME=		${DISTNAME:S/libapache-mod/ap/:S/_/-/}
PKGREVISION=		3
WRKSRC=			${WRKDIR}/${DISTNAME:S/_/-/}
CATEGORIES=		www databases security
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/liba/libapache-mod-auth-mysql/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://packages.debian.org/unstable/web/libapache-mod-auth-mysql.html
COMMENT=		Apache (${PKG_APACHE}) module to allow authentication against a MySQL database

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/include/mysql	\
			--with-mysql-libs=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mysql-client}/include/mysql
LDFLAGS+=		-L${BUILDLINK_PREFIX.mysql-client}/lib/mysql	\
			-lmysqlclient					\
			${COMPILER_RPATH_FLAG}${PREFIX}/lib/mysql

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
	fi
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_mysql
	${INSTALL_DATA} ${WRKSRC}/DIRECTIVES ${PREFIX}/share/doc/mod_auth_mysql
	${INSTALL_DATA} ${WRKSRC}/USAGE ${PREFIX}/share/doc/mod_auth_mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
