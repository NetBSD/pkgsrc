# $NetBSD: module.mk,v 1.1 2017/07/10 17:29:58 schmonz Exp $

.include "../../textproc/xapian/Makefile.common"

DISTNAME=		xapian-bindings-${VERSION}
PKGNAME_MODULE=		${DISTNAME:S/-bindings-/-/}

DESCR_SRC=		${PKGDIR}/../../textproc/xapian/DESCR
DISTINFO_FILE=		${PKGDIR}/../../textproc/xapian/distinfo

.include "../../textproc/xapian/buildlink3.mk"
