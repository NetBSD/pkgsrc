# $NetBSD: Makefile,v 1.2.2.1 2002/06/30 06:24:20 jlam Exp $
#

DISTNAME=	source-highlight-1.2.1
SVR4_PKGNAME=	srchl
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=source-highlight/}

MAINTAINER=	seb@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/src-highlite/source-highlight.html
COMMENT=	Highlight syntax of C, C++ or Java source into HTML document

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

.include "../../mk/bsd.prefs.mk"

.ifdef SOURCE_HIGHLIGHT_INPUT_CHROOT
CONFIGURE_ARGS+=	--enable-input-chroot=${SOURCE_HIGHLIGHT_INPUT_CHROOT}
BUILD_DEFS+=		SOURCE_HIGHLIGHT_INPUT_CHROOT
.endif

.include "../../mk/bsd.pkg.mk"
