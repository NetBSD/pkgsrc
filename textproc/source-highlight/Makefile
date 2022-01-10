# $NetBSD: Makefile,v 1.68 2022/01/10 01:46:45 ryoon Exp $

DISTNAME=	source-highlight-3.1.9
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=src-highlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/src-highlite/
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

# gmake and gsed are necessary for testing only,
# but the tools handling is somewhat broken in that regard
USE_TOOLS+=	gsed gmake bash:test
TEST_TARGET=	check

# bash scripts
CHECK_PORTABILITY_SKIP+= \
	lib/tests/valgrind_test.sh.in \
	tests/valgrind_suppressions.sh.in \
	tests/valgrind_test.sh.in \
	tests/valgrind_tests.sh.in

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
