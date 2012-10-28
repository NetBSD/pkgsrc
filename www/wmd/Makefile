# $NetBSD: Makefile,v 1.3 2012/10/28 06:31:09 asau Exp $
#

DISTNAME=		wmd-1.0.1
CATEGORIES=		www
MASTER_SITES=		http://wmd-editor.com/downloads/
EXTRACT_SUFX=		.zip

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://wmd-editor.com/
COMMENT=		Simple, lightweight WYSIWYM Markdown editor
#LICENSE=		"next release will be under an MIT-style license"

USE_LANGUAGES=		# none
NO_BUILD=		yes

INSTALLATION_DIRS=	share/doc/wmd share/wmd/images

do-install:
	cd ${WRKSRC} &&							\
	for f in *.txt *Example.html; do				\
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/doc/wmd; \
	done;								\
	for f in wmd/*.js; do						\
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/wmd;	\
	done;								\
	for f in wmd/images/*.png; do					\
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/wmd/images; \
	done

.include "../../mk/bsd.pkg.mk"
