# $NetBSD: Makefile,v 1.15 2006/09/09 02:46:08 obache Exp $

DISTNAME=	dic
PKGNAME=	stardic-1.31
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://download.linuxbyte.net/Chinese/dictionary/

MAINTAINER=	rxg@NetBSD.org
COMMENT=	English-Chinese dictionary

DIST_SUBDIR=	${PKGNAME_NOREV}

MAKE_FILE=	makefile
USE_LANGUAGES=	c c++

FONTS_DIRS.x11+=	${PREFIX}/share/stardic/hzfont
REQD_DIRS+=		${PREFIX}/share/stardic ${PREFIX}/share/stardic/hzfont

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
