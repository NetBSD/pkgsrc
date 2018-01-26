# $NetBSD: buildlink3.mk,v 1.1 2018/01/26 14:35:31 triaxx Exp $

BUILDLINK_TREE+=	py-swiftclient

.if !defined(PY_SWIFTCLIENT_BUILDLINK3_MK)
PY_SWIFTCLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-swiftclient+=	${PYPKGPREFIX}-swiftclient>=3.1.0
BUILDLINK_PKGSRCDIR.py-swiftclient?=	../../www/py-swiftclient
.endif	# PY_SWIFTCLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-swiftclient
