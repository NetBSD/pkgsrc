# $NetBSD: Makefile,v 1.17 2005/10/10 09:05:59 seb Exp $
#

DISTNAME=	source-highlight-2.1.2
SVR4_PKGNAME=	srchl
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=src-highlite/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/src-highlite/
COMMENT=	Highlight syntax of various languages source into HTML document

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

INFO_FILES=	source-highlight.info

# this is only really needed for the 'test' target
USE_TOOLS+=	gmake gsed
TEST_TARGET=	check

BUILDLINK_TRANSFORM+=	l:boost_regex:boost_regex-mt

.include "../../mk/bsd.prefs.mk"

.if "${OPSYS}" == "NetBSD"
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
