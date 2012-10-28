# $NetBSD: Makefile,v 1.18 2012/10/28 06:30:17 asau Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-x11-/}
PKGREVISION=	1

FILESDIR=	${.CURDIR}/../../www/htmldoc/files
PATCHDIR=	${.CURDIR}/../../www/htmldoc/patches
PKGDIR=		${.CURDIR}/../../www/htmldoc

DESCR_SRC=	${.CURDIR}/DESCR

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.htmldoc+=	x11

.include "../../www/htmldoc/Makefile"
