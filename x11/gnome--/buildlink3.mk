# $NetBSD: buildlink3.mk,v 1.1 2004/04/26 22:07:06 snj Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNOMEMM_BUILDLINK3_MK:=	${GNOMEMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnomemm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnomemm}
BUILDLINK_PACKAGES+=	gnomemm

.if !empty(GNOMEMM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnomemm+=	gnome-->=1.2.4nb1
BUILDLINK_PKGSRCDIR.gnomemm?=	../../x11/gnome--
.endif	# GNOMEMM_BUILDLINK3_MK

.include "../../devel/libsigc++10/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/gtk--/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
