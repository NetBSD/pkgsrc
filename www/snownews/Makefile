# $NetBSD: Makefile,v 1.54 2019/08/11 13:25:08 wiz Exp $

DISTNAME=	snownews-1.5.12
PKGREVISION=	16
CATEGORIES=	www
MASTER_SITES=	http://kiza.kcore.de/software/snownews/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kiza.kcore.de/software/snownews/
COMMENT=	Small, curses based RSS feed reader
LICENSE=	gnu-gpl-v2

DEPENDS+=		p5-XML-LibXML>=1.58:../../textproc/p5-XML-LibXML

HAS_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt perl

REPLACE_PERL+=		configure opml2snow

CONFIG_SHELL=		perl
CONFIGURE_ARGS+=	--prefix=${PREFIX}
MAKE_ENV+=		EXTRA_CFLAGS=${CFLAGS:Q}

INCOMPAT_CURSES=	NetBSD-[0-4].*-*	#WA_BOLD, WA_REVERSE, KEY_RESIZE
FAKE_NCURSES=		yes

.include "options.mk"

post-configure:
	${ECHO} LOCALEPATH=${PREFIX}/${PKGLOCALEDIR}/locale >> ${WRKSRC}/platform_settings
	${ECHO} MANPATH=${PREFIX}/${PKGMANDIR} >> ${WRKSRC}/platform_settings

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
