# $NetBSD: Makefile,v 1.14 2005/06/17 04:49:49 jlam Exp $

DISTNAME=	snownews-1.5.5.1
CATEGORIES=	www
MASTER_SITES=	http://home.kcore.de/~kiza/software/snownews/download/

MAINTAINER=	pkgsrc@bjan.freeshell.org
HOMEPAGE=	http://home.kcore.de/~kiza/software/snownews/
COMMENT=	Small, curses based RSS feed reader

BUILD_USES_MSGFMT=	YES

USE_TOOLS+=		gmake
USE_NCURSES=		# missing WA_BOLD, WA_REVERSE, KEY_RESIZE
USE_PKGLOCALEDIR=	YES

MAKE_ENV+=	PKGLOCALEDIR=${PKGLOCALEDIR:Q}
MAKE_ENV+=	EXTRA_CFLAGS=${CFLAGS:Q} LOCALBASE=${LOCALBASE:Q}

# XXX -lintl hack suggested by Jeremy C. Reed: blocking on PR #23369
.include "../../devel/gettext-lib/buildlink3.mk"
MAKE_ENV+=	EXTRA_LDFLAGS="${LDFLAGS} ${BUILDLINK_LDADD.gettext}"

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snownews ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/opml2snow ${PREFIX}/bin
.for M in de fr it nl ru_RU.KOI8-R
	${INSTALL_DATA_DIR} ${PREFIX}/man/${M}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/${M}/snownews.1 ${PREFIX}/man/${M}/man1
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/man/snownews.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/opml2snow.1 ${PREFIX}/man/man1
.for L in de es nl pt_BR ru sl zh_TW
	${INSTALL_DATA_DIR} ${PREFIX}/${PKGLOCALEDIR}/locale/${L}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${L}.mo ${PREFIX}/${PKGLOCALEDIR}/locale/${L}/LC_MESSAGES/snownews.mo
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
