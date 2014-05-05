# $NetBSD: buildlink3.mk,v 1.43 2014/05/05 00:48:30 ryoon Exp $

BUILDLINK_TREE+=	gtksourceview

.if !defined(GTKSOURCEVIEW_BUILDLINK3_MK)
GTKSOURCEVIEW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtksourceview+=	gtksourceview>=1.8.5<2
BUILDLINK_ABI_DEPENDS.gtksourceview+=	gtksourceview>=1.8.5nb28
BUILDLINK_PKGSRCDIR.gtksourceview?=	../../x11/gtksourceview

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKSOURCEVIEW_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtksourceview
