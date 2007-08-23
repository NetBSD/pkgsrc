# $NetBSD: Makefile,v 1.29 2007/08/23 09:56:55 joerg Exp $

DISTNAME=	swish-e-2.4.5
PKGREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES=	http://swish-e.org/distribution/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://swish-e.org/
COMMENT=	Simple web indexing for humans - enhanced

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-libxml2=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

USE_TOOLS+=	perl:run
REPLACE_PERL=	prog-bin/*.pl conf/*.pl filter-bin/*.pl html/*.pl

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
