# $NetBSD: Makefile,v 1.25 2008/01/04 20:05:12 jmmv Exp $
#

DISTNAME=	source-highlight-2.5
SVR4_PKGNAME=	srchl
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=src-highlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/src-highlite/
COMMENT=	Highlight syntax of various languages source into HTML document

DEPENDS+=	exctags-[0-9]*:../../devel/exctags

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
CONFIGURE_ENV+=	CTAGS=${LOCALBASE}/bin/exctags

INFO_FILES=	YES

# this is only really needed for the 'test' target
USE_TOOLS+=	gmake gsed
TEST_TARGET=	check

CONFIGURE_ARGS+=	--with-boost-regex

BUILDLINK_TRANSFORM+=	l:boost_regex:boost_regex-mt

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# We really need GNU sed not NetBSD's GNuish sed
TOOLS_PLATFORM.gsed=	# empty
.endif

# Build is broken with input chroot
#.ifdef SOURCE_HIGHLIGHT_INPUT_CHROOT
#CONFIGURE_ARGS+=	--enable-input-chroot=${SOURCE_HIGHLIGHT_INPUT_CHROOT:Q}
#BUILD_DEFS+=		SOURCE_HIGHLIGHT_INPUT_CHROOT
#.endif

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
