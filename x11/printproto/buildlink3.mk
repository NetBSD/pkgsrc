# $NetBSD: buildlink3.mk,v 1.4 2018/03/07 11:57:39 wiz Exp $

BUILDLINK_TREE+=	printproto

.if !defined(PRINTPROTO_BUILDLINK3_MK)
PRINTPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.printproto+=	printproto>=1.0.3
BUILDLINK_PKGSRCDIR.printproto?=	../../x11/printproto

BUILDLINK_DEPMETHOD.printproto?=	build

.include "../../x11/xorgproto/buildlink3.mk"
.endif # PRINTPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-printproto
