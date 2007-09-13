# $NetBSD: Makefile,v 1.30 2007/09/13 23:26:24 wiz Exp $

DISTNAME=	snownews-1.5.7
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://kiza.kcore.de/software/snownews/download/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://kiza.kcore.de/software/snownews/
COMMENT=	Small, curses based RSS feed reader

DEPENDS+=		p5-XML-LibXML>=1.58:../../textproc/p5-XML-LibXML

HAS_CONFIGURE=		YES
USE_NCURSES=		YES # missing WA_BOLD, WA_REVERSE, KEY_RESIZE
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		msgfmt perl:run

REPLACE_PERL+=		configure opml2snow snowsync

CONFIG_SHELL=		perl
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
MAKE_ENV+=	PKG_LOCALEDIR=${PKGLOCALEDIR:Q}
MAKE_ENV+=	EXTRA_CFLAGS=${CFLAGS:Q}

# XXX -lintl hack suggested by Jeremy C. Reed: blocking on PR #23369
.include "../../devel/gettext-lib/buildlink3.mk"
MAKE_ENV+=	EXTRA_LDFLAGS=${LDFLAGS:Q}" "${BUILDLINK_LDADD.gettext:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snownews ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/opml2snow ${PREFIX}/bin
.for lang in de fr it nl ru_RU.KOI8-R
	${INSTALL_DATA_DIR} ${PREFIX}/${PKGMANDIR}/${lang}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/${lang}/snownews.1 ${PREFIX}/${PKGMANDIR}/${lang}/man1
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/man/snownews.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/opml2snow.1 ${PREFIX}/${PKGMANDIR}/man1
.for lang in de es ja nl pl pt_BR ru sl zh_TW zh_CN
	${INSTALL_DATA_DIR} ${PREFIX}/${PKGLOCALEDIR}/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo ${PREFIX}/${PKGLOCALEDIR}/locale/${lang}/LC_MESSAGES/snownews.mo
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
