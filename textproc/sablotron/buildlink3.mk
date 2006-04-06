# $NetBSD: buildlink3.mk,v 1.5 2006/04/06 06:22:52 reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SABLOTRON_BUILDLINK3_MK:=	${SABLOTRON_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	sablotron
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsablotron}
BUILDLINK_PACKAGES+=	sablotron

.if !empty(SABLOTRON_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.sablotron+=	sablotron>=1.0
BUILDLINK_ABI_DEPENDS.sablotron+=	sablotron>=1.0.2nb2
BUILDLINK_PKGSRCDIR.sablotron?=	../../textproc/sablotron
.endif	# SABLOTRON_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
