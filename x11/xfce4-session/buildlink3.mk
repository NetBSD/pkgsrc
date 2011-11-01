# $NetBSD: buildlink3.mk,v 1.27 2011/11/01 06:03:12 sbd Exp $

BUILDLINK_TREE+=	xfce4-session

.if !defined(XFCE4_SESSION_BUILDLINK3_MK)
XFCE4_SESSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-session+=	xfce4-session>=4.6.0
BUILDLINK_ABI_DEPENDS.xfce4-session?=	xfce4-session>=4.6.1nb6
BUILDLINK_PKGSRCDIR.xfce4-session?=	../../x11/xfce4-session

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/xfconf/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.endif # XFCE4_SESSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-session
