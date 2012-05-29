# $NetBSD: buildlink3.mk,v 1.3 2012/05/29 14:18:48 wiz Exp $

BUILDLINK_TREE+=	printproto

.if !defined(PRINTPROTO_BUILDLINK3_MK)
PRINTPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.printproto+=	printproto>=1.0.3
BUILDLINK_PKGSRCDIR.printproto?=	../../x11/printproto

BUILDLINK_DEPMETHOD.printproto?=	build

.include "../../x11/xproto/buildlink3.mk"
.endif # PRINTPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-printproto
