# $NetBSD: buildlink3.mk,v 1.6 2009/09/16 01:15:34 reed Exp $

BUILDLINK_TREE+=	xfce4-orage

.if !defined(XFCE4_ORAGE_BUILDLINK3_MK)
XFCE4_ORAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-orage+=	xfce4-orage>=4.6.0
BUILDLINK_PKGSRCDIR.xfce4-orage?=	../../time/xfce4-orage

.endif # XFCE4_ORAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-orage
