# $NetBSD: Makefile,v 1.9 2026/02/15 09:12:54 wiz Exp $

DISTNAME=	unicode-emoji-${EMOJI_VERSION}
CATEGORIES=	textproc
MASTER_SITES=	https://www.unicode.org/Public/emoji/${EMOJI_VERSION}/
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${EMOJI_FILES}
EXTRACT_SUFX=	# none

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://home.unicode.org/emoji/about-emoji/
COMMENT=	Unicode Emoji Data Files
LICENSE=	unicode

USE_LANGUAGES=	# none
NO_BUILD=	YES
NO_CONFIGURE=	YES

WRKSRC=		${WRKDIR}
EMOJIDIR=	${PREFIX}/share/unicode/emoji

EMOJI_VERSION=	15.1
EMOJI_FILES=	ReadMe.txt
EMOJI_FILES+=	emoji-sequences.txt
EMOJI_FILES+=	emoji-test.txt
EMOJI_FILES+=	emoji-zwj-sequences.txt

INSTALLATION_DIRS=	${EMOJIDIR}

do-install:
	@for EMOJI_FILE in ${EMOJI_FILES}; do				\
	  ${ECHO} "Installing emoji file $${EMOJI_FILE} ... ";		\
	  ${INSTALL_DATA} ${WRKSRC}/$${EMOJI_FILE}			\
	    ${DESTDIR}${EMOJIDIR};					\
	done

.include "../../mk/bsd.pkg.mk"
