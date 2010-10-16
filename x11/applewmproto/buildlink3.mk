# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/10/16 13:08:13 obache Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_DEPMETHOD.applewmproto?=	build

BUILDLINK_TREE+=	applewmproto

.if !defined(APPLEWMPROTO_BUILDLINK3_MK)
APPLEWMPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.applewmproto+=	applewmproto>=1.4.1
BUILDLINK_PKGSRCDIR.applewmproto?=	../../x11/applewmproto

.include "../../x11/xproto/buildlink3.mk"
.endif # APPLEWMPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-applewmproto
