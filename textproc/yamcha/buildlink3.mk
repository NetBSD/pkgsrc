# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/05/19 12:08:02 obache Exp $

BUILDLINK_TREE+=	yamcha

.if !defined(YAMCHA_BUILDLINK3_MK)
YAMCHA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yamcha+=	yamcha>=0.33
BUILDLINK_PKGSRCDIR.yamcha?=	../../textproc/yamcha

.include "../../math/TinySVM/buildlink3.mk"
.endif # YAMCHA_BUILDLINK3_MK

BUILDLINK_TREE+=	-yamcha
