# $NetBSD: buildlink2.mk,v 1.4 2004/03/08 20:27:17 minskim Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pytk
BUILDLINK_DEPENDS.pytk?=	${PYPKGPREFIX}-Tk-*
BUILDLINK_PKGSRCDIR.pytk?=	../../x11/py-Tk

.include "../../x11/tk83/buildlink2.mk"
