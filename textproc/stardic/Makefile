# $NetBSD: Makefile,v 1.19 2011/12/09 14:36:36 drochner Exp $

DISTNAME=	dic
PKGNAME=	stardic-1.31
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	http://download.linuxbyte.net/Chinese/dictionary/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	rxg@NetBSD.org
COMMENT=	English-Chinese dictionary

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=	makefile
USE_LANGUAGES=	c c++

FONTS_DIRS.x11+=	${PREFIX}/share/stardic/hzfont
REQD_DIRS+=		${PREFIX}/share/stardic ${PREFIX}/share/stardic/hzfont

INSTALLATION_DIRS=	bin

post-extract:
	chmod -R u+w,go-w ${WRKSRC}

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
