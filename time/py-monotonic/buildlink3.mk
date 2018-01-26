# $NetBSD: buildlink3.mk,v 1.1 2018/01/26 14:42:06 triaxx Exp $

BUILDLINK_TREE+=	py-monotonic

.if !defined(PY_MONOTONIC_BUILDLINK3_MK)
PY_MONOTONIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-monotonic+=	${PYPKGPREFIX}-monotonic>=0.1
BUILDLINK_PKGSRCDIR.py-monotonic?=	../../time/py-monotonic
.endif	# PY_MONOTONIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-monotonic
