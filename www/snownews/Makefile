# $NetBSD: Makefile,v 1.5 2004/01/24 15:23:47 grant Exp $

DISTNAME=	snownews-1.4.2
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://home.kcore.de/~kiza/software/snownews/download/

MAINTAINER=	pkgsrc@bjan.freeshell.org
HOMEPAGE=	http://home.kcore.de/~kiza/software/snownews/
COMMENT=	Small, curses based RSS feed reader

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2= 	YES
USE_GNU_TOOLS+=		make
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
