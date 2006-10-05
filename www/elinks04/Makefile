# $NetBSD: Makefile,v 1.7 2006/10/05 02:58:02 rillig Exp $

DISTNAME=		elinks-0.4.3
PKGREVISION=		3
CATEGORIES=		www
MASTER_SITES=		http://elinks.or.cz/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dawszy@arhea.net
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
