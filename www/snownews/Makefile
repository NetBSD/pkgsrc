# $NetBSD: Makefile,v 1.1.1.1 2003/12/27 23:04:23 wiz Exp $

DISTNAME=       snownews-1.4.2
CATEGORIES=     www
MASTER_SITES=   http://home.kcore.de/~kiza/software/snownews/download/

MAINTAINER=     bjan+pkgsrc@bjan.net
HOMEPAGE=	http://home.kcore.de/~kiza/software/snownews/
COMMENT=        Small, curses based RSS feed reader

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2= 	YES
USE_GMAKE=		YES
USE_NCURSES=		# missing WA_BOLD, WA_REVERSE, KEY_RESIZE
USE_PKGLOCALEDIR=	YES

MAKE_ENV+=	PKGLOCALEDIR=${PKGLOCALEDIR} GMAKE=${GMAKE}
MAKE_ENV+=	EXTRA_CFLAGS="${CFLAGS}"

# XXX -lintl hack suggested by Jeremy C. Reed: blocking on PR #23369
.include "../../devel/gettext-lib/buildlink2.mk"
MAKE_ENV+=	EXTRA_LDFLAGS="${LDFLAGS} ${_BLNK_INTL_LDFLAGS}"

.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
