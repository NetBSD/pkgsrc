# $NetBSD: buildlink3.mk,v 1.1 2018/01/26 14:24:29 triaxx Exp $

BUILDLINK_TREE+=	py-cloudfiles

.if !defined(PY_CLOUDFILES_BUILDLINK3_MK)
PY_CLOUDFILES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-cloudfiles+=	${PYPKGPREFIX}-cloudfiles>=1.3.0
BUILDLINK_PKGSRCDIR.py-cloudfiles?=	../../www/py-cloudfiles
.endif	# PY_CLOUDFILES_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-cloudfiles
