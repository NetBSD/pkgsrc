# $NetBSD: buildlink.mk,v 1.1 2002/01/15 18:26:39 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pymxdatetime?= ${PYPKGPREFIX}-mxDateTime-*
DEPENDS+= ${BUILDLINK_DEPENDS.pymxdatetime}:../../time/py-mxDateTime
