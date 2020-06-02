# $NetBSD: Makefile,v 1.57 2020/06/02 08:24:58 adam Exp $

DISTNAME=	snownews-1.6.10
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=kouya/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kouya/snownews
COMMENT=	Small, curses based RSS feed reader
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-XML-LibXML>=1.58:../../textproc/p5-XML-LibXML

USE_TOOLS+=	gmake msgfmt perl pkg-config
HAS_CONFIGURE=	yes
FAKE_NCURSES=	yes

REPLACE_PERL+=	opml2snow

AUTO_MKDIRS=	yes

CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	--mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

# AUTO_MKDIRS can't handle this one.
INSTALLATION_DIRS+=	share/locale/be@latin/LC_MESSAGES

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
