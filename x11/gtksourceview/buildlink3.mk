# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:42 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKSOURCEVIEW_BUILDLINK3_MK:=	${GTKSOURCEVIEW_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtksourceview
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtksourceview}
BUILDLINK_PACKAGES+=	gtksourceview

.if !empty(GTKSOURCEVIEW_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtksourceview+=	gtksourceview>=0.7.0nb8
BUILDLINK_PKGSRCDIR.gtksourceview?=	../../x11/gtksourceview

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# GTKSOURCEVIEW_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
