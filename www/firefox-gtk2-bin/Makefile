# $NetBSD: Makefile,v 1.6.2.1 2005/03/22 19:13:56 snj Exp $

MOZILLA=	firefox
MOZ_VER=	1.0.1
MOZ_DISTVER=	${MOZ_VER}

HOMEPAGE=	http://www.mozilla.org/projects/firefox/
COMMENT=	Lightweight gecko-based web browser (gtk2 binary pkg)

MOZ_GTK2=	YES
DIST_SUBDIR=	${MOZILLA}-gtk2/${MOZ_DISTDIR}

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/mozilla-bin/Makefile.common"
