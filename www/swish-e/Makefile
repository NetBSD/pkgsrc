# $NetBSD: Makefile,v 1.13 2004/01/23 21:55:48 jmmv Exp $
# FreeBSD Id: ports/www/swish-e/Makefile,v 1.3 1999/08/31 02:43:18 peter Exp

DISTNAME=	swish-e-2.4.1
PKGREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES=	http://swish-e.org/Download/

MAINTAINER=	dotz@irc.pl
HOMEPAGE= 	http://swish-e.org/
COMMENT= 	Simple web indexing for humans - enhanced

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-libxml2=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

REPLACE_PERL=		prog-bin/*.pl conf/*.pl filter-bin/*.pl html/*.pl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD"
PLIST_SUBST+=	LIBSWISH_E="@comment "
.else
PLIST_SUBST+=	LIBSWISH_E=
.endif

.include "../../devel/pcre/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
