# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:56 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pytk
BUILDLINK_DEPENDS.pytk?=	${PYPKGPREFIX}-Tk-*
BUILDLINK_PKGSRCDIR.pytk?=	../../x11/py-Tk
