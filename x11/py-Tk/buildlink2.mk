# $NetBSD: buildlink2.mk,v 1.6 2004/03/29 05:05:50 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pytk
BUILDLINK_PKGBASE.pytk?=	${PYPKGPREFIX}-Tk
BUILDLINK_DEPENDS.pytk?=	${PYPKGPREFIX}-Tk-[0-9]*
BUILDLINK_PKGSRCDIR.pytk?=	../../x11/py-Tk

.include "../../x11/tk/buildlink2.mk"
