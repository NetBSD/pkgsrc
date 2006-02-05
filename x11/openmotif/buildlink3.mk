# $NetBSD: buildlink3.mk,v 1.4 2006/02/05 23:11:40 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OPENMOTIF_BUILDLINK3_MK:=	${OPENMOTIF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openmotif
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopenmotif}
BUILDLINK_PACKAGES+=	openmotif

.if !empty(OPENMOTIF_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.openmotif+=	openmotif>=2.2.3
BUILDLINK_RECOMMENDED.openmotif?=	openmotif>=2.2.3nb2
BUILDLINK_PKGSRCDIR.openmotif?=	../../x11/openmotif
.endif	# OPENMOTIF_BUILDLINK3_MK

.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
