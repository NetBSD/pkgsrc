# $NetBSD: Makefile,v 1.42 2009/07/02 20:04:12 drochner Exp $

DISTNAME=		elinks-0.12pre2
PKGNAME=		${DISTNAME:S/pre/rc/}
PKGREVISION=		2
CATEGORIES=		www
MASTER_SITES=		http://elinks.or.cz/download/ \
			http://ftp.icm.edu.pl/packages/elinks/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://elinks.or.cz/
COMMENT=		Extended/Enhanced Links

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/${PKGBASE}
CONFIGURE_ARGS+=	--enable-256-colors
CONFIGURE_ARGS+=	--enable-utf-8

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
