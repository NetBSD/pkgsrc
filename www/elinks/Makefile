# $NetBSD: Makefile,v 1.6 2003/04/29 23:26:37 jtb Exp $

DISTNAME=		elinks-0.4.2
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://elinks.or.cz/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dawszy@arhea.net
HOMEPAGE=		http://elinks.or.cz/
COMMENT=		Extended/Enhanced Links

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-x

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../lang/lua4/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
