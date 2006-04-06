# $NetBSD: buildlink3.mk,v 1.3 2006/04/06 06:22:56 reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XCOMPOSITE_BUILDLINK3_MK:=	${XCOMPOSITE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xcomposite
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXcomposite}
BUILDLINK_PACKAGES+=	Xcomposite

.if !empty(XCOMPOSITE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.Xcomposite+=		Xcomposite>=1.0.1
BUILDLINK_ABI_DEPENDS.Xcomposite?=	Xcomposite>=1.0.1nb2
BUILDLINK_PKGSRCDIR.Xcomposite?=	../../x11/Xcomposite
.endif	# XCOMPOSITE_BUILDLINK3_MK

.include "../../x11/Xfixes/buildlink3.mk"
.include "../../x11/compositeext/buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
