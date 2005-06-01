# $NetBSD: buildlink3.mk,v 1.5 2005/06/01 18:03:27 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XFIXES_BUILDLINK3_MK:=	${XFIXES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xfixes
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXfixes}
BUILDLINK_PACKAGES+=	Xfixes

.if !empty(XFIXES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.Xfixes+=	Xfixes>=2.0.0
BUILDLINK_RECOMMENDED.Xfixes+=	Xfixes>=2.0.1nb1
BUILDLINK_PKGSRCDIR.Xfixes?=	../../x11/Xfixes
.endif	# XFIXES_BUILDLINK3_MK

.include "../../mk/x11.buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
