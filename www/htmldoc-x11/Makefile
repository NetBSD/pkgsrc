# $NetBSD: Makefile,v 1.19 2012/11/15 13:44:14 gdt Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-x11-/}
PKGREVISION=	2

FILESDIR=	${.CURDIR}/../../www/htmldoc/files
PATCHDIR=	${.CURDIR}/../../www/htmldoc/patches
PKGDIR=		${.CURDIR}/../../www/htmldoc

DESCR_SRC=	${.CURDIR}/DESCR

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.htmldoc+=	x11

.include "../../www/htmldoc/Makefile"
