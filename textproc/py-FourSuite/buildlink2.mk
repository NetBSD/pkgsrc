# $NetBSD: buildlink2.mk,v 1.1 2002/12/04 12:47:42 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyfoursuite
BUILDLINK_DEPENDS.pyfoursuite?=	${PYPKGPREFIX}-FourSuite-*
BUILDLINK_PKGSRCDIR.pyfoursuite?=	../../textproc/py-FourSuite
