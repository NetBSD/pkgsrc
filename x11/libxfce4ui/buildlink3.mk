# $NetBSD: buildlink3.mk,v 1.7 2020/03/08 16:48:27 wiz Exp $

BUILDLINK_TREE+=	libxfce4ui

.if !defined(LIBXFCE4UI_BUILDLINK3_MK)
LIBXFCE4UI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4ui+=	libxfce4ui>=4.12.1
BUILDLINK_ABI_DEPENDS.libxfce4ui+=	libxfce4ui>=4.14.1nb1
BUILDLINK_PKGSRCDIR.libxfce4ui?=	../../x11/libxfce4ui

.include "../../devel/xfce4-conf/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.endif # LIBXFCE4UI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4ui
