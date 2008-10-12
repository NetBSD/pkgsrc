# $NetBSD: buildlink3.mk,v 1.1 2008/10/12 18:55:15 kefren Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
P5_GTK2_BUILDLINK3_MK:=	${P5_GTK2_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	p5-gtk2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Np5-gtk2}
BUILDLINK_PACKAGES+=	p5-gtk2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}p5-gtk2

.if ${P5_GTK2_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.p5-gtk2+=	p5-gtk2>=1.182
BUILDLINK_PKGSRCDIR.p5-gtk2?=	../../x11/p5-gtk2
.endif	# P5_GTK2_BUILDLINK3_MK

.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../graphics/p5-cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
