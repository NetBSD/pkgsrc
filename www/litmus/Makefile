# $NetBSD: Makefile,v 1.7 2020/03/01 18:07:51 nia Exp $

DISTNAME=	litmus-0.13
PKGREVISION=	4
CATEGORIES=	www
#MASTER_SITES=	http://www.webdav.org/neon/litmus/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.webdav.org/neon/litmus/
COMMENT=	WebDAV server protocol compliance test suite
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-ssl

.include "../../textproc/expat/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
