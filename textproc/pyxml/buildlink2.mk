# $NetBSD: buildlink2.mk,v 1.1 2002/10/24 22:24:24 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyxml
BUILDLINK_DEPENDS.pyxml?=	${PYPKGPREFIX}-xml-*
BUILDLINK_PKGSRCDIR.pyxml?=	../../textproc/pyxml
