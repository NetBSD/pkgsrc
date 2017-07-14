# $NetBSD: module.mk,v 1.2 2017/07/14 12:55:45 joerg Exp $

.include "../../textproc/xapian/Makefile.common"

DISTNAME=		xapian-bindings-${VERSION}
PKGNAME_MODULE=		${DISTNAME:S/-bindings-/-/}

DESCR_SRC=		${PKGDIR}/../../textproc/xapian/DESCR
DISTINFO_FILE=		${PKGDIR}/../../textproc/xapian/distinfo-bindings
PATCHDIR=		${PKGDIR}/../../textproc/xapian/patches-bindings

.include "../../textproc/xapian/buildlink3.mk"
