# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:24 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pymxdatetime
BUILDLINK_DEPENDS.pymxdatetime?=	${PYPKGPREFIX}-mxDateTime-*
BUILDLINK_PKGSRCDIR.pymxdatetime?=	../../time/py-mxDateTime
