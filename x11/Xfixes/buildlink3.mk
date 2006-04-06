# $NetBSD: buildlink3.mk,v 1.7 2006/04/06 06:22:56 reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XFIXES_BUILDLINK3_MK:=	${XFIXES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xfixes
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXfixes}
BUILDLINK_PACKAGES+=	Xfixes

.if !empty(XFIXES_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.Xfixes+=	Xfixes>=2.0.0
BUILDLINK_ABI_DEPENDS.Xfixes+=	Xfixes>=2.0.1nb2
BUILDLINK_PKGSRCDIR.Xfixes?=	../../x11/Xfixes
.endif	# XFIXES_BUILDLINK3_MK

.include "../../mk/x11.buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
