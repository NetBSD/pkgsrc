# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:36:51 wiz Exp $

BUILDLINK_TREE+=	yamcha

.if !defined(YAMCHA_BUILDLINK3_MK)
YAMCHA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yamcha+=	yamcha>=0.33
BUILDLINK_ABI_DEPENDS.yamcha?=	yamcha>=0.33nb12
BUILDLINK_PKGSRCDIR.yamcha?=	../../textproc/yamcha

.include "../../math/TinySVM/buildlink3.mk"
.endif # YAMCHA_BUILDLINK3_MK

BUILDLINK_TREE+=	-yamcha
