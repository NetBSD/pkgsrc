# $NetBSD: Makefile,v 1.57 2019/07/01 04:07:53 ryoon Exp $

DISTNAME=	source-highlight-3.1.8
PKGREVISION=	9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=src-highlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/src-highlite/
COMMENT=	Highlight syntax of various languages source into HTML document
LICENSE=	gnu-gpl-v3

DEPENDS+=	exctags-[0-9]*:../../devel/exctags

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-boost-regex=boost_regex
CONFIGURE_ARGS+=	--without-bash-completion
CONFIGURE_ENV+=		CTAGS=${PREFIX}/bin/exctags
CONFIGURE_ENV+=		ac_cv_header_stdbool_h=yes
CONFIGURE_ENV+=		ac_cv_ctags_flags=yes

PKGCONFIG_OVERRIDE=	source-highlight.pc.in

INFO_FILES=	YES

# this is only really needed for the 'test' target
USE_TOOLS+=	gmake gsed
TEST_TARGET=	check

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
