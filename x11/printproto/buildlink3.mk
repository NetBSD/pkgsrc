# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:48 joerg Exp $

BUILDLINK_DEPMETHOD.printproto?=	build

BUILDLINK_TREE+=	printproto

.if !defined(PRINTPROTO_BUILDLINK3_MK)
PRINTPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.printproto+=	printproto>=1.0.3
BUILDLINK_PKGSRCDIR.printproto?=	../../x11/printproto

.include "../../x11/xproto/buildlink3.mk"
.endif # PRINTPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-printproto
