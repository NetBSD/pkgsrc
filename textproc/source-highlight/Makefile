# $NetBSD: Makefile,v 1.35 2012/07/02 13:37:42 adam Exp $

DISTNAME=	source-highlight-3.1.4
PKGREVISION=	4
SVR4_PKGNAME=	srchl
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=src-highlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/src-highlite/
COMMENT=	Highlight syntax of various languages source into HTML document
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	exctags-[0-9]*:../../devel/exctags

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-boost-regex=boost_regex
CONFIGURE_ARGS+=	--without-bash-completion
CONFIGURE_ENV+=		CTAGS=${LOCALBASE}/bin/exctags

PKGCONFIG_OVERRIDE=	source-highlight.pc.in

INFO_FILES=	YES

# this is only really needed for the 'test' target
USE_TOOLS+=	gmake gsed
TEST_TARGET=	check

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
