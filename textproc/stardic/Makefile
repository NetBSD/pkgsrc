# $NetBSD: Makefile,v 1.14 2006/04/28 18:48:25 joerg Exp $

DISTNAME=	dic
PKGNAME=	stardic-1.31
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://download.linuxbyte.net/Chinese/dictionary/

MAINTAINER=	rxg@NetBSD.org
COMMENT=	English-Chinese dictionary

DIST_SUBDIR=	${PKGNAME_NOREV}

MAKEFILE=	makefile
USE_LANGUAGES=	c c++

FONTS_DIRS.x11+=	${PREFIX}/share/stardic/hzfont
REQD_DIRS+=		${PREFIX}/share/stardic ${PREFIX}/share/stardic/hzfont

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
