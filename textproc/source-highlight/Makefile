# $NetBSD: Makefile,v 1.15 2004/10/21 00:15:47 seb Exp $
#

DISTNAME=	source-highlight-1.11
SVR4_PKGNAME=	srchl
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=src-highlite/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/src-highlite/
COMMENT=	Highlight syntax of various languages source into HTML document

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_LANGUAGES=	c c++

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

.ifdef SOURCE_HIGHLIGHT_INPUT_CHROOT
CONFIGURE_ARGS+=	--enable-input-chroot=${SOURCE_HIGHLIGHT_INPUT_CHROOT}
BUILD_DEFS+=		SOURCE_HIGHLIGHT_INPUT_CHROOT
.endif

.include "../../mk/bsd.pkg.mk"
