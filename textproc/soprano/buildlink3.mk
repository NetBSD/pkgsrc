# $NetBSD: buildlink3.mk,v 1.40 2020/01/12 20:19:59 ryoon Exp $

BUILDLINK_TREE+=	soprano

.if !defined(SOPRANO_BUILDLINK3_MK)
SOPRANO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.soprano+=	soprano>=2.0.3
BUILDLINK_ABI_DEPENDS.soprano+=	soprano>=2.9.4nb20
BUILDLINK_PKGSRCDIR.soprano?=	../../textproc/soprano

.include "../../textproc/libclucene/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.endif # SOPRANO_BUILDLINK3_MK

BUILDLINK_TREE+=	-soprano
