# $NetBSD: Makefile,v 1.8 2010/02/12 21:12:58 joerg Exp $

DISTNAME=	mod_auth_kerb-5.4
PKGNAME=	${DISTNAME:S/mod/${APACHE_PKG_PREFIX}/:S/_/-/g}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modauthkerb/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://modauthkerb.sourceforge.net/
COMMENT=	Module to allow Apache authentication using Kerberos
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_APACHE_ACCEPTED=	apache2 apache22

CONFLICTS=	ap-auth-kerb-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-krb4
CONFIGURE_ARGS+=	--with-apache=${BUILDLINK_PREFIX.apache}
CONFIGURE_ARGS+=	APXS=${APXS}
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

APACHE_MODULE=		yes

INSTALLATION_DIRS+=	lib/httpd

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/.libs/mod_auth_kerb.so \
	    ${DESTDIR}${PREFIX}/lib/httpd

.include "../../mk/apache.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
