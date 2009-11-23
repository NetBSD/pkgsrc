# $NetBSD: Makefile,v 1.7 2009/11/23 16:59:18 joerg Exp $

DISTNAME=	mod_auth_kerb-5.4
PKGNAME=	${DISTNAME:S/mod/${APACHE_PKG_PREFIX}/:S/_/-/g}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modauthkerb/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://modauthkerb.sourceforge.net/
COMMENT=	Module to allow Apache authentication using Kerberos
LICENSE=	modified-bsd

PKG_APACHE_ACCEPTED=	apache2 apache22

CONFLICTS=	ap-auth-kerb-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-krb4
CONFIGURE_ARGS+=	--with-apache=${BUILDLINK_PREFIX.apache}
CONFIGURE_ARGS+=	APXS=${APXS}
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

APACHE_MODULE=		yes

.include "../../mk/apache.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
