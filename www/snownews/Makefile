# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:27 tv Exp $

DISTNAME=	snownews-1.5.1
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://home.kcore.de/~kiza/software/snownews/download/

MAINTAINER=	pkgsrc@bjan.freeshell.org
HOMEPAGE=	http://home.kcore.de/~kiza/software/snownews/
COMMENT=	Small, curses based RSS feed reader

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3= 	YES
USE_GNU_TOOLS+=		make
USE_NCURSES=		# missing WA_BOLD, WA_REVERSE, KEY_RESIZE
USE_PKGLOCALEDIR=	YES

MAKE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}" MAKE="${GMAKE}"
MAKE_ENV+=	EXTRA_CFLAGS="${CFLAGS}" LOCALBASE="${LOCALBASE}"

# XXX -lintl hack suggested by Jeremy C. Reed: blocking on PR #23369
.include "../../devel/gettext-lib/buildlink3.mk"
MAKE_ENV+=	EXTRA_LDFLAGS="${LDFLAGS} ${BUILDLINK_LDADD.gettext}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snownews ${LOCALBASE}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/opml2snow ${LOCALBASE}/bin
.for M in de fr it nl
	${INSTALL_DATA_DIR} ${LOCALBASE}/man/${M}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/${M}/snownews.1 ${LOCALBASE}/man/${M}/man1
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/man/snownews.1 ${LOCALBASE}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/opml2snow.1 ${LOCALBASE}/man/man1
.for L in de es fr it nl sl zh_TW
	${INSTALL_DATA_DIR} ${LOCALBASE}/${PKGLOCALEDIR}/locale/${L}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${L}.mo ${LOCALBASE}/${PKGLOCALEDIR}/locale/${L}/LC_MESSAGES/snownews.mo
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
