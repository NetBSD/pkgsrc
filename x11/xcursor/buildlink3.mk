# $NetBSD: buildlink3.mk,v 1.22 2006/12/12 21:52:38 joerg Exp $

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

# Xfixes/buildlink3.mk is included by xcursor/builtin.mk
#.include "../../x11/Xfixes/buildlink3.mk"

.include "../../x11/Xrender/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
