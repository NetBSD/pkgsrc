# $NetBSD: buildlink3.mk,v 1.7 2006/04/06 06:22:55 reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTKHTML_BUILDLINK3_MK:=	${GTKHTML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkhtml
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkhtml}
BUILDLINK_PACKAGES+=	gtkhtml

.if !empty(GTKHTML_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gtkhtml?=	gtkhtml>=1.1.10nb5
BUILDLINK_ABI_DEPENDS.gtkhtml?=	gtkhtml>=1.1.10nb7
BUILDLINK_PKGSRCDIR.gtkhtml?=	../../www/gtkhtml
.endif	# GTKHTML_BUILDLINK3_MK

.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../www/glibwww/buildlink3.mk"
.include "../../www/libghttp/buildlink3.mk"
.include "../../x11/control-center/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
