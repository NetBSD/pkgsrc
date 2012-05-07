# $NetBSD: buildlink3.mk,v 1.10 2012/05/07 01:54:08 dholland Exp $

BUILDLINK_TREE+=	gtk+extra

.if !defined(GTK_EXTRA_BUILDLINK3_MK)
GTK_EXTRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk+extra+=	gtk+extra>=0.99.17nb2
BUILDLINK_ABI_DEPENDS.gtk+extra+=	gtk+extra>=0.99.17nb6
BUILDLINK_PKGSRCDIR.gtk+extra?=	../../x11/gtk+extra

.include "../../x11/gtk/buildlink3.mk"
.endif # GTK_EXTRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk+extra
