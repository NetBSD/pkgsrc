# $NetBSD: buildlink3.mk,v 1.2 2011/01/23 23:56:53 tnn Exp $

BUILDLINK_TREE+=	rep-gtk2

.if !defined(REP_GTK2_BUILDLINK3_MK)
REP_GTK2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rep-gtk2+=	rep-gtk2>=0.90.4
BUILDLINK_PKGSRCDIR.rep-gtk2?=	../../x11/rep-gtk2

.endif	# REP_GTK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-rep-gtk2
