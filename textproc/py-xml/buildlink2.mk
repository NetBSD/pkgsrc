# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/23 15:25:39 recht Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyxml
BUILDLINK_DEPENDS.pyxml?=	${PYPKGPREFIX}-xml-*
BUILDLINK_PKGSRCDIR.pyxml?=	../../textproc/py-xml
