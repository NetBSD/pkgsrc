# $NetBSD: buildlink2.mk,v 1.5 2004/03/10 19:29:31 minskim Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pytk
BUILDLINK_DEPENDS.pytk?=	${PYPKGPREFIX}-Tk-*
BUILDLINK_PKGSRCDIR.pytk?=	../../x11/py-Tk

.include "../../x11/tk/buildlink2.mk"
