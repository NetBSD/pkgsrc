# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/10/16 13:10:05 obache Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	libAppleWM

.if !defined(LIBAPPLEWM_BUILDLINK3_MK)
LIBAPPLEWM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libAppleWM+=	libAppleWM>=1.4.0
BUILDLINK_PKGSRCDIR.libAppleWM?=	../../x11/libAppleWM

.include "../../x11/applewmproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # LIBAPPLEWM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libAppleWM
