# $NetBSD: buildlink2.mk,v 1.2 2004/03/29 05:05:45 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyfoursuite
BUILDLINK_PKGBASE.pyfoursuite?=	${PYPKGPREFIX}-FourSuite
BUILDLINK_DEPENDS.pyfoursuite?=	${PYPKGPREFIX}-FourSuite-[0-9]*
BUILDLINK_PKGSRCDIR.pyfoursuite?=	../../textproc/py-FourSuite
