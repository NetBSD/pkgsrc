# $NetBSD: buildlink3.mk,v 1.14 2004/10/03 00:18:39 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XCURSOR_BUILDLINK3_MK:=	${XCURSOR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xcursor
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxcursor}
BUILDLINK_PACKAGES+=	xcursor

.if !empty(XCURSOR_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xcursor+=	xcursor>=1.0
BUILDLINK_RECOMMENDED.xcursor+=	xcursor>=1.1.1nb2
BUILDLINK_PKGSRCDIR.xcursor?=	../../x11/xcursor
.endif	# XCURSOR_BUILDLINK3_MK

USE_X11=	yes

# Xfixes/buildlink3.mk is included by xcursor/builtin.mk
#.include "../../x11/Xfixes/buildlink3.mk"

.include "../../x11/Xrender/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
