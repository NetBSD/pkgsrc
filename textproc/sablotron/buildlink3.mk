# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:11:11 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SABLOTRON_BUILDLINK3_MK:=	${SABLOTRON_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	sablotron
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsablotron}
BUILDLINK_PACKAGES+=	sablotron
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}sablotron

.if !empty(SABLOTRON_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.sablotron+=	sablotron>=1.0
BUILDLINK_ABI_DEPENDS.sablotron+=	sablotron>=1.0.2nb2
BUILDLINK_PKGSRCDIR.sablotron?=	../../textproc/sablotron
.endif	# SABLOTRON_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
