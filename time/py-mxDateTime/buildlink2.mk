# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:45 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pymxdatetime
BUILDLINK_DEPENDS.pymxdatetime?=	${PYPKGPREFIX}-mxDateTime-*
BUILDLINK_PKGSRCDIR.pymxdatetime?=	../../time/py-mxDateTime
