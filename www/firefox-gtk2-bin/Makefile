# $NetBSD: Makefile,v 1.6.2.2 2005/03/24 17:38:49 snj Exp $

MOZILLA=	firefox
MOZ_VER=	1.0.2
MOZ_DISTVER=	${MOZ_VER}

HOMEPAGE=	http://www.mozilla.org/projects/firefox/
COMMENT=	Lightweight gecko-based web browser (gtk2 binary pkg)

MOZ_GTK2=	YES
DIST_SUBDIR=	${MOZILLA}-gtk2/${MOZ_DISTDIR}

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/mozilla-bin/Makefile.common"
