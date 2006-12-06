# $NetBSD: Makefile,v 1.8 2006/12/06 21:15:34 reed Exp $

DISTNAME=		elinks-0.4.3
PKGREVISION=		3
CATEGORIES=		www
MASTER_SITES=		http://elinks.or.cz/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://elinks.or.cz/
COMMENT=		Extended/Enhanced Links

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-x
SKIP_PORTABILITY_CHECK=	yes	# The offending code is commented out.

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
