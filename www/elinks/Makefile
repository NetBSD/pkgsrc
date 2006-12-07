# $NetBSD: Makefile,v 1.27.2.1 2006/12/07 14:25:27 ghen Exp $

DISTNAME=		elinks-0.11.2
CATEGORIES=		www
MASTER_SITES=		http://elinks.or.cz/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://elinks.or.cz/
COMMENT=		Extended/Enhanced Links

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--enable-256-colors
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
