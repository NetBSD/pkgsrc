# $NetBSD: buildlink3.mk,v 1.3 2014/01/03 05:03:51 ryoon Exp $

BUILDLINK_TREE+=	rep-gtk2

.if !defined(REP_GTK2_BUILDLINK3_MK)
REP_GTK2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rep-gtk2+=	rep-gtk2>=0.90.8.1
BUILDLINK_PKGSRCDIR.rep-gtk2?=	../../x11/rep-gtk2

.endif	# REP_GTK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-rep-gtk2
