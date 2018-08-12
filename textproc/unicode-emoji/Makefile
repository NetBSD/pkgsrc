# $NetBSD: Makefile,v 1.2 2018/08/12 11:42:16 tsutsui Exp $

DISTNAME=	unicode-emoji-${EMOJI_VERSION}
CATEGORIES=	textproc
MASTER_SITES=	http://www.unicode.org/Public/emoji/${EMOJI_VERSION}/
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${EMOJI_FILES}
EXTRACT_SUFX=	# none

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	http://www.unicode.org/emoji/
COMMENT=	Unicode Emoji Data Files
LICENSE=	unicode

USE_LANGUAGES=	# none
NO_BUILD=	YES
NO_CONFIGURE=	YES

WRKSRC=		${WRKDIR}
EMOJIDIR=	${PREFIX}/share/unicode/emoji

EMOJI_VERSION=	11.0
EMOJI_FILES=	ReadMe.txt
EMOJI_FILES+=	emoji-data.txt
EMOJI_FILES+=	emoji-sequences.txt
EMOJI_FILES+=	emoji-test.txt
EMOJI_FILES+=	emoji-variation-sequences.txt
EMOJI_FILES+=	emoji-zwj-sequences.txt

INSTALLATION_DIRS=	${EMOJIDIR}

do-install:
	@for EMOJI_FILE in ${EMOJI_FILES}; do				\
	  ${ECHO} "Installing emoji file $${EMOJI_FILE} ... ";		\
	  ${INSTALL_DATA} ${WRKSRC}/$${EMOJI_FILE}			\
	    ${DESTDIR}${EMOJIDIR};					\
	done

.include "../../mk/bsd.pkg.mk"
