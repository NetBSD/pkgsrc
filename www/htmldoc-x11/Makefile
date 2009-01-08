# $NetBSD: Makefile,v 1.16 2009/01/08 11:57:24 obache Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-x11-/}

FILESDIR=	${.CURDIR}/../../www/htmldoc/files
PATCHDIR=	${.CURDIR}/../../www/htmldoc/patches
PKGDIR=		${.CURDIR}/../../www/htmldoc

DESCR_SRC=	${.CURDIR}/DESCR

# Mirror PKG_DESTDIR_SUPPORT setting from htmldoc/Makefile.
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.htmldoc+=	x11

.include "../../www/htmldoc/Makefile"
