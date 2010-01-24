# $NetBSD: Makefile,v 1.17 2010/01/24 13:26:12 wiz Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-x11-/}
PKGREVISION=	1

FILESDIR=	${.CURDIR}/../../www/htmldoc/files
PATCHDIR=	${.CURDIR}/../../www/htmldoc/patches
PKGDIR=		${.CURDIR}/../../www/htmldoc

DESCR_SRC=	${.CURDIR}/DESCR

# Mirror PKG_DESTDIR_SUPPORT setting from htmldoc/Makefile.
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.htmldoc+=	x11

.include "../../www/htmldoc/Makefile"
