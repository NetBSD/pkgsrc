# $NetBSD: buildlink3.mk,v 1.1 2013/05/31 00:33:43 rodent Exp $

BUILDLINK_TREE+=	applewmproto

.if !defined(APPLEWMPROTO_BUILDLINK3_MK)
APPLEWMPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.applewmproto?=	build

BUILDLINK_API_DEPENDS.applewmproto+=	applewmproto>=1.4.1
BUILDLINK_PKGSRCDIR.applewmproto?=	../../wm/applewmproto

.include "../../x11/xproto/buildlink3.mk"
.endif # APPLEWMPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-applewmproto
