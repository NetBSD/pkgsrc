# $NetBSD: Makefile,v 1.22 2005/07/16 01:19:26 jlam Exp $

DISTNAME=	swish-e-2.4.1
PKGREVISION=	4
CATEGORIES=	www textproc
MASTER_SITES=	http://swish-e.org/Download/

MAINTAINER=	dotz@irc.pl
HOMEPAGE= 	http://swish-e.org/
COMMENT= 	Simple web indexing for humans - enhanced

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-libxml2=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

USE_TOOLS+=	perl:run
REPLACE_PERL=	prog-bin/*.pl conf/*.pl filter-bin/*.pl html/*.pl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD"
PLIST_SUBST+=	LIBSWISH_E="@comment "
.else
PLIST_SUBST+=	LIBSWISH_E=
.endif

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
