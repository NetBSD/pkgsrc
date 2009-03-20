# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:42 joerg Exp $

BUILDLINK_TREE+=	gtksourceview-sharp2

.if !defined(GTKSOURCEVIEW_SHARP2_BUILDLINK3_MK)
GTKSOURCEVIEW_SHARP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtksourceview-sharp2+=	gtksourceview-sharp2>=0.10
BUILDLINK_PKGSRCDIR.gtksourceview-sharp2?=	../../x11/gtksourceview-sharp2
.endif # GTKSOURCEVIEW_SHARP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtksourceview-sharp2
