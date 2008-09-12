# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/09/12 11:15:38 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
WXGTK28_CONTRIB_BUILDLINK3_MK:=	${WXGTK28_CONTRIB_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	wxGTK28-contrib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NwxGTK28-contrib}
BUILDLINK_PACKAGES+=	wxGTK28-contrib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}wxGTK28-contrib

.if ${WXGTK28_CONTRIB_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.wxGTK28-contrib+=	wxGTK28-contrib>=2.8.8
BUILDLINK_PKGSRCDIR.wxGTK28-contrib?=	../../x11/wxGTK28-contrib
.endif	# WXGTK28_CONTRIB_BUILDLINK3_MK

.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
