# $NetBSD: buildlink3.mk,v 1.1 2004/02/15 09:45:30 recht Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XFIXES_BUILDLINK3_MK:=	${XFIXES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xfixes
.endif

.if !empty(XFIXES_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			Xfixes
BUILDLINK_DEPENDS.Xfixes+=		Xfixes>=2.0.0
BUILDLINK_PKGSRCDIR.Xfixes?=		../../x11/Xfixes

.include "../../x11/fixesext/buildlink3.mk"

.endif # XFIXES_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
