# $NetBSD: Makefile,v 1.34 2009/06/01 11:56:43 obache Exp $

DISTNAME=	snownews-1.5.11
CATEGORIES=	www
MASTER_SITES=	http://kiza.kcore.de/software/snownews/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kiza.kcore.de/software/snownews/
COMMENT=	Small, curses based RSS feed reader
LICENSE=	gnu-gpl-v2

DEPENDS+=		p5-XML-LibXML>=1.58:../../textproc/p5-XML-LibXML

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt perl

REPLACE_PERL+=		configure opml2snow

CONFIG_SHELL=		perl
CONFIGURE_ARGS+=	--prefix=${PREFIX}
MAKE_ENV+=		EXTRA_CFLAGS=${CFLAGS:Q}

post-configure:
	${ECHO} LOCALEPATH=${PREFIX}/${PKGLOCALEDIR}/locale >> ${WRKSRC}/platform_settings
	${ECHO} MANPATH=${PREFIX}/${PKGMANDIR} >> ${WRKSRC}/platform_settings

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
