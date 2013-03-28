# $NetBSD: Makefile,v 1.30 2013/03/28 21:40:50 joerg Exp $
#

DISTNAME=		mod-auth-mysql_4.3.9.orig
PKGNAME=		${APACHE_PKG_PREFIX}-auth-mysql-4.3.9
PKGREVISION=		3
WRKSRC=			${WRKDIR}/${DISTNAME:S/_/-/}
CATEGORIES=		www databases security
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/m/mod-auth-mysql/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://packages.debian.org/sid/libapache2-mod-auth-mysql
COMMENT=		Module to allow apache authentication against a MySQL database

PKG_APACHE_ACCEPTED=	apache2 apache22

CONFLICTS=	ap-auth-mysql-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/${BUILDLINK_INCDIRS.mysql-client}	\
			--with-mysql-libs=${BUILDLINK_PREFIX.mysql-client}/${BUILDLINK_LIBDIRS.mysql-client}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/${BUILDLINK_LIBDIRS.mysql-client}

WRKSRC=			${WRKDIR}/${DISTNAME:S/.orig//:S/_/-/}

.include "../../mk/apache.mk"

.if ${PKG_APACHE} == "apache13"
CONFIGURE_ARGS+=	--enable-apache13 --disable-apache2
.else
CONFIGURE_ARGS+=	--disable-apache13 --enable-apache2
.endif

APACHE_MODULE=		YES
APACHE_MODULE_NAME=	mod_auth_mysql.so

INSTALLATION_DIRS=	lib/httpd share/doc/mod_auth_mysql

do-install:
	if [ -f ${WRKSRC}/.libs/apache2_mod_auth_mysql.so ]; then	\
		${INSTALL_DATA} \
			${WRKSRC}/.libs/apache2_mod_auth_mysql.so \
			${DESTDIR}${PREFIX}/lib/httpd/mod_auth_mysql.so;   \
	elif [ -f ${WRKSRC}/.libs/${PKG_APACHE}_mod_auth_mysql.so ]; then	\
		${INSTALL_DATA} \
			${WRKSRC}/.libs/${PKG_APACHE}_mod_auth_mysql.so \
			${DESTDIR}${PREFIX}/lib/httpd/mod_auth_mysql.so;   \
	elif [ -f ${WRKSRC}/libs/${PKG_APACHE}_mod_auth_mysql.so ]; then \
		${INSTALL_DATA} \
			${WRKSRC}/libs/${PKG_APACHE}_mod_auth_mysql.so  \
			${DESTDIR}${PREFIX}/lib/httpd/mod_auth_mysql.so;   \
	elif [ -f ${WRKSRC}/${PKG_APACHE}_mod_auth_mysql.so ]; then \
		${INSTALL_DATA} \
			${WRKSRC}/${PKG_APACHE}_mod_auth_mysql.so  \
			${DESTDIR}${PREFIX}/lib/httpd/mod_auth_mysql.so;   \
	fi
	${INSTALL_DATA} ${WRKSRC}/DIRECTIVES ${DESTDIR}${PREFIX}/share/doc/mod_auth_mysql
	${INSTALL_DATA} ${WRKSRC}/USAGE ${DESTDIR}${PREFIX}/share/doc/mod_auth_mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
