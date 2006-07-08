# $NetBSD: buildlink3.mk,v 1.13 2006/07/08 23:11:14 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKSOURCEVIEW_BUILDLINK3_MK:=	${GTKSOURCEVIEW_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtksourceview
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtksourceview}
BUILDLINK_PACKAGES+=	gtksourceview
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtksourceview

.if !empty(GTKSOURCEVIEW_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gtksourceview+=	gtksourceview>=1.2.0
BUILDLINK_ABI_DEPENDS.gtksourceview?=	gtksourceview>=1.6.1nb1
BUILDLINK_PKGSRCDIR.gtksourceview?=	../../x11/gtksourceview
.endif	# GTKSOURCEVIEW_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
