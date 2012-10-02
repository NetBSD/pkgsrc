# $NetBSD: buildlink3.mk,v 1.34 2012/10/02 17:12:23 tron Exp $

BUILDLINK_TREE+=	xfce4-session

.if !defined(XFCE4_SESSION_BUILDLINK3_MK)
XFCE4_SESSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-session+=	xfce4-session>=4.6.0
BUILDLINK_ABI_DEPENDS.xfce4-session+=	xfce4-session>=4.6.1nb13
BUILDLINK_PKGSRCDIR.xfce4-session?=	../../x11/xfce4-session

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/xfconf/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.endif # XFCE4_SESSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-session
