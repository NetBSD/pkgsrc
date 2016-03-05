# $NetBSD: Makefile,v 1.4 2016/03/05 11:29:38 jperkin Exp $

DISTNAME=	litmus-0.13
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/neon/litmus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.webdav.org/neon/litmus/
COMMENT=	WebDAV server protocol compliance test suite
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=openssl

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
