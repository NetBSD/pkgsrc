# $NetBSD: Makefile,v 1.15 2008/04/24 15:20:06 jlam Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-x11-/}

FILESDIR=	${.CURDIR}/../../www/htmldoc/files
PATCHDIR=	${.CURDIR}/../../www/htmldoc/patches
PKGDIR=		${.CURDIR}/../../www/htmldoc

DESCR_SRC=	${.CURDIR}/DESCR

# Mirror PKG_DESTDIR_SUPPORT setting from htmldoc/Makefile.
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.htmldoc+=	htmldoc-gui

.include "../../www/htmldoc/Makefile"
