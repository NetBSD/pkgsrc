# $NetBSD: Makefile,v 1.4.6.1 2007/01/28 20:17:52 ghen Exp $

DISTNAME=	mod_auth_kerb-5.3
PKGNAME=	${APACHE_PKG_PREFIX}-auth-kerb-5.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modauthkerb/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://modauthkerb.sourceforge.net/
COMMENT=	Module to allow Apache authentication using Kerberos

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
