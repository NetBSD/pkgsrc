# $NetBSD: buildlink3.mk,v 1.5 2006/02/05 23:11:44 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
WXGTK_CONTRIB_BUILDLINK3_MK:=	${WXGTK_CONTRIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wxGTK-contrib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NwxGTK-contrib}
BUILDLINK_PACKAGES+=	wxGTK-contrib

.if !empty(WXGTK_CONTRIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.wxGTK-contrib+=	wxGTK-contrib>=2.6.0
BUILDLINK_RECOMMENDED.wxGTK-contrib?=	wxGTK-contrib>=2.6.2nb2
BUILDLINK_PKGSRCDIR.wxGTK-contrib?=	../../x11/wxGTK-contrib

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"

.endif	# WXGTK_CONTRIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
