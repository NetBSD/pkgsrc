# $NetBSD: Makefile,v 1.5 2004/10/04 11:28:45 wiz Exp $

MOZILLA=	firefox
MOZ_VER=	0.10.1
MOZ_DISTVER=	1.0PR
# Added because 0.10 and 0.10.1 have the same distname.
# Can be removed on update.
DIST_SUBDIR=	${MOZILLA}-${MOZ_VER}

HOMEPAGE=	http://www.mozilla.org/projects/firefox/
COMMENT=	Lightweight gecko-based web browser (gtk2 binary pkg)

MOZ_GTK2=	YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/mozilla-bin/Makefile.common"
