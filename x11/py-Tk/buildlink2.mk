# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:54 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pytk
BUILDLINK_DEPENDS.pytk?=	${PYPKGPREFIX}-Tk-*
BUILDLINK_PKGSRCDIR.pytk?=	../../x11/py-Tk
