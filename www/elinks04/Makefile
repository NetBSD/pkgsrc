# $NetBSD: Makefile,v 1.4 2004/04/28 00:28:18 snj Exp $

DISTNAME=		elinks-0.4.3
PKGREVISION=		2
CATEGORIES=		www
MASTER_SITES=		http://elinks.or.cz/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dawszy@arhea.net
HOMEPAGE=		http://elinks.or.cz/
COMMENT=		Extended/Enhanced Links

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-x

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
