# $NetBSD: buildlink3.mk,v 1.1.1.1 2003/12/16 08:51:42 recht Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XCURSOR_BUILDLINK3_MK:=	${XCURSOR_BUILDLINK3_MK}+

.if !empty(XCURSOR_BUILDLINK3_MK:M\+)
.  include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.xcursor?=	xcursor>=1.1.1
BUILDLINK_PKGSRCDIR.xcursor?=	../../x11/xcursor
BUILDLINK_PACKAGES+=		xcursor
.endif	# XCURSOR_BUILDLINK3_MK

BUILDLINK_IS_BUILTIN.xcursor=	NO

.if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=		xcursor
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
