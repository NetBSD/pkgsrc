# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 09:12:15 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENBOX_BUILDLINK3_MK:=	${OPENBOX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openbox
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopenbox}
BUILDLINK_PACKAGES+=	openbox

.if !empty(OPENBOX_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.openbox+=	openbox>=3.1
BUILDLINK_PKGSRCDIR.openbox?=	../../wm/openbox
.endif	# OPENBOX_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
