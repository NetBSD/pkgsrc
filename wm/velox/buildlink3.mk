# $NetBSD: buildlink3.mk,v 1.4 2022/08/11 05:09:21 gutteridge Exp $

BUILDLINK_TREE+=	velox

.if !defined(VELOX_BUILDLINK3_MK)
VELOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.velox+=	velox>=0.0.3.20191211
BUILDLINK_ABI_DEPENDS.velox?=	velox>=0.0.3.20200119nb4
BUILDLINK_PKGSRCDIR.velox?=	../../wm/velox

.include "../../wm/swc/buildlink3.mk"
.endif	# VELOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-velox
