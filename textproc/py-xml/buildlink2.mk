# $NetBSD: buildlink2.mk,v 1.2 2004/03/29 05:05:45 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyxml
BUILDLINK_PKGBASE.pyxml?=	${PYPKGPREFIX}-xml
BUILDLINK_DEPENDS.pyxml?=	${PYPKGPREFIX}-xml-[0-9]*
BUILDLINK_PKGSRCDIR.pyxml?=	../../textproc/py-xml
