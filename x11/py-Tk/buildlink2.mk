# $NetBSD: buildlink2.mk,v 1.3 2002/10/24 19:33:39 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pytk
BUILDLINK_DEPENDS.pytk?=	${PYPKGPREFIX}-Tk-*
BUILDLINK_PKGSRCDIR.pytk?=	../../x11/py-Tk

.include "../../x11/tk/buildlink2.mk"
