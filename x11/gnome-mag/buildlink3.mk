# $NetBSD: buildlink3.mk,v 1.11 2006/02/05 23:11:33 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_MAG_BUILDLINK3_MK:=	${GNOME_MAG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-mag
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-mag}
BUILDLINK_PACKAGES+=	gnome-mag

.if !empty(GNOME_MAG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-mag+=	gnome-mag>=0.12.0
BUILDLINK_RECOMMENDED.gnome-mag?=	gnome-mag>=0.12.2nb2
BUILDLINK_PKGSRCDIR.gnome-mag?=	../../x11/gnome-mag
.endif	# GNOME_MAG_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
