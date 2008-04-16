# $NetBSD: Makefile,v 1.33 2008/04/16 08:54:28 wiz Exp $

DISTNAME=	snownews-1.5.9
CATEGORIES=	www
MASTER_SITES=	http://kiza.kcore.de/software/snownews/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kiza.kcore.de/software/snownews/
COMMENT=	Small, curses based RSS feed reader

DEPENDS+=		p5-XML-LibXML>=1.58:../../textproc/p5-XML-LibXML

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
USE_NCURSES=		yes	# missing WA_BOLD, WA_REVERSE, KEY_RESIZE
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt perl:run

REPLACE_PERL+=		configure opml2snow snowsync

CONFIG_SHELL=		perl
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
MAKE_ENV+=		PKG_LOCALEDIR=${PKGLOCALEDIR:Q}
MAKE_ENV+=		EXTRA_CFLAGS=${CFLAGS:Q}

# XXX -lintl hack suggested by Jeremy C. Reed: blocking on PR #23369
.include "../../devel/gettext-lib/buildlink3.mk"
MAKE_ENV+=	EXTRA_LDFLAGS=${LDFLAGS:Q}" "${BUILDLINK_LDADD.gettext:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snownews ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/opml2snow ${DESTDIR}${PREFIX}/bin
.for lang in de fr it nl ru_RU.KOI8-R
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/${lang}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/${lang}/snownews.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/${lang}/man1
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/man/snownews.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/opml2snow.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for lang in de es ja nl pl pt_BR ru sl zh_TW zh_CN
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo	\
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/${lang}/LC_MESSAGES/snownews.mo
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
