# $NetBSD: Makefile,v 1.3 2006/06/08 12:15:57 joerg Exp $

DISTNAME=	mod_auth_kerb-5.0rc7
PKGNAME=	${APACHE_PKG_PREFIX}-auth-kerb-5.0rc7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modauthkerb/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://modauthkerb.sourceforge.net/
COMMENT=	Module to allow Apache authentication using Kerberos

CONFLICTS=	ap-auth-kerb-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-krb4
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

APACHE_MODULE=		yes

.include "../../mk/apache.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
