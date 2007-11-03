# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/11/03 17:24:41 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKSOURCEVIEW2_BUILDLINK3_MK:=	${GTKSOURCEVIEW2_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gtksourceview2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtksourceview2}
BUILDLINK_PACKAGES+=	gtksourceview2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtksourceview2

.if ${GTKSOURCEVIEW2_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gtksourceview2+=	gtksourceview2>=2.0.0
BUILDLINK_PKGSRCDIR.gtksourceview2?=	../../x11/gtksourceview2
.endif	# GTKSOURCEVIEW2_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
