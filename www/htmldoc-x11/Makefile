# $NetBSD: Makefile,v 1.14 2008/04/23 20:23:38 jlam Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-x11-/}

FILESDIR=	${.CURDIR}/../../www/htmldoc/files
PATCHDIR=	${.CURDIR}/../../www/htmldoc/patches
PKGDIR=		${.CURDIR}/../../www/htmldoc

DESCR_SRC=	${.CURDIR}/DESCR

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.htmldoc+=	htmldoc-gui

.include "../../www/htmldoc/Makefile"
