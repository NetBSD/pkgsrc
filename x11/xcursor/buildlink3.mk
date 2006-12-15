# $NetBSD: buildlink3.mk,v 1.23 2006/12/15 20:33:05 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XCURSOR_BUILDLINK3_MK:=	${XCURSOR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xcursor
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxcursor}
BUILDLINK_PACKAGES+=	xcursor
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xcursor

.if !empty(XCURSOR_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xcursor+=	xcursor>=1.0
BUILDLINK_ABI_DEPENDS.xcursor+=	xcursor>=1.1.2nb1
BUILDLINK_PKGSRCDIR.xcursor?=	../../x11/xcursor
.endif	# XCURSOR_BUILDLINK3_MK

.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
