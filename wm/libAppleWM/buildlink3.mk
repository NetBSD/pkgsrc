# $NetBSD: buildlink3.mk,v 1.2 2014/11/16 20:14:59 wiz Exp $

BUILDLINK_TREE+=	libAppleWM

.if !defined(LIBAPPLEWM_BUILDLINK3_MK)
LIBAPPLEWM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libAppleWM+=	libAppleWM>=1.4.0
BUILDLINK_PKGSRCDIR.libAppleWM?=	../../wm/libAppleWM

.include "../../wm/applewmproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # LIBAPPLEWM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libAppleWM
