# $NetBSD: Makefile,v 1.13 2004/04/27 05:44:23 snj Exp $

DISTNAME=		elinks-0.9.1
PKGREVISION=		2
CATEGORIES=		www
MASTER_SITES=		http://elinks.or.cz/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dawszy@arhea.net
HOMEPAGE=		http://elinks.or.cz/
COMMENT=		Extended/Enhanced Links

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make

CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--enable-256-colors
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
