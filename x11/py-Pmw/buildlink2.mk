# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:53 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pypmw
BUILDLINK_DEPENDS.pypmw?=	${PYPKGPREFIX}-Pmw-*
BUILDLINK_PKGSRCDIR.pypmw?=	../../x11/py-Pmw
