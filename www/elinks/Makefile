# $NetBSD: Makefile,v 1.10 2004/01/23 22:39:23 recht Exp $

DISTNAME=		elinks-0.9.1
CATEGORIES=		www
MASTER_SITES=		http://elinks.or.cz/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dawszy@arhea.net
HOMEPAGE=		http://elinks.or.cz/
COMMENT=		Extended/Enhanced Links

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make

CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--enable-256-colors
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../lang/lua/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
