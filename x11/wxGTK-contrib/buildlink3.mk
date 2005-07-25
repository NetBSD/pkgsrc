# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/07/25 20:26:55 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
WXGTK_CONTRIB_BUILDLINK3_MK:=	${WXGTK_CONTRIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wxGTK-contrib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NwxGTK-contrib}
BUILDLINK_PACKAGES+=	wxGTK-contrib

.if !empty(WXGTK_CONTRIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.wxGTK-contrib+=	wxGTK-contrib>=2.4.2
BUILDLINK_PKGSRCDIR.wxGTK-contrib?=	../../wip/wxGTK-contrib

.if !empty(WXGTK_USE_GTK1:M[Yy][Ee][Ss])
.  include "../../x11/gtk/buildlink3.mk"
.else
.  include "../../x11/gtk2/buildlink3.mk"
.endif
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.endif	# WXGTK_CONTRIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
