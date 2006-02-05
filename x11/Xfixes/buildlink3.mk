# $NetBSD: buildlink3.mk,v 1.6 2006/02/05 23:11:31 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XFIXES_BUILDLINK3_MK:=	${XFIXES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xfixes
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXfixes}
BUILDLINK_PACKAGES+=	Xfixes

.if !empty(XFIXES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.Xfixes+=	Xfixes>=2.0.0
BUILDLINK_RECOMMENDED.Xfixes+=	Xfixes>=2.0.1nb2
BUILDLINK_PKGSRCDIR.Xfixes?=	../../x11/Xfixes
.endif	# XFIXES_BUILDLINK3_MK

.include "../../mk/x11.buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
