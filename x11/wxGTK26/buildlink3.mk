# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/09/22 19:44:05 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WXGTK_BUILDLINK3_MK:=	${WXGTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wxGTK
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NwxGTK}
BUILDLINK_PACKAGES+=	wxGTK
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}wxGTK

.if !empty(WXGTK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.wxGTK+=	wxGTK>=2.6.0nb2
BUILDLINK_ABI_DEPENDS.wxGTK+=	wxGTK>=2.6.3nb1
BUILDLINK_PKGSRCDIR.wxGTK?=	../../x11/wxGTK
.endif	# WXGTK_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
