# $NetBSD: buildlink3.mk,v 1.1.1.2 2008/02/20 11:21:54 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKSOURCEVIEW2_BUILDLINK3_MK:=	${GTKSOURCEVIEW2_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gtksourceview2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtksourceview2}
BUILDLINK_PACKAGES+=	gtksourceview2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtksourceview2

.if ${GTKSOURCEVIEW2_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gtksourceview2+=	gtksourceview2>=2.0.2
BUILDLINK_PKGSRCDIR.gtksourceview2?=	../../x11/gtksourceview
.endif	# GTKSOURCEVIEW2_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
