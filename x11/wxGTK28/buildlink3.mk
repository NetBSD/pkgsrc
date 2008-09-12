# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/09/12 11:09:49 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WXGTK28_BUILDLINK3_MK:=	${WXGTK_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	wxGTK28
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NwxGTK28}
BUILDLINK_PACKAGES+=	wxGTK28
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}wxGTK28

.if ${WXGTK28_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.wxGTK28+=	wxGTK28>=2.8.8
BUILDLINK_PKGSRCDIR.wxGTK28?=	../../x11/wxGTK28
.endif	# WXGTK_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
