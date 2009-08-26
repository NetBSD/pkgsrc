# $NetBSD: buildlink3.mk,v 1.24 2009/08/26 19:57:02 sno Exp $

BUILDLINK_TREE+=	libxfce4mcs

.if !defined(LIBXFCE4MCS_BUILDLINK3_MK)
LIBXFCE4MCS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4mcs+=	libxfce4mcs>=4.4.3nb1
BUILDLINK_ABI_DEPENDS.libxfce4mcs?=	libxfce4mcs>=4.4.3nb2
BUILDLINK_PKGSRCDIR.libxfce4mcs?=	../../x11/libxfce4mcs

.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # LIBXFCE4MCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4mcs
