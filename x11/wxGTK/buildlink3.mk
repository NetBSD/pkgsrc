# $NetBSD: buildlink3.mk,v 1.1 2004/02/15 20:38:37 recht Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WXGTK_BUILDLINK3_MK:=	${WXGTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wxGTK
.endif

.if !empty(WXGTK_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			wxGTK
BUILDLINK_DEPENDS.wxGTK+=		wxGTK>=2.4.2
BUILDLINK_PKGSRCDIR.wxGTK?=		../../x11/wxGTK

.include "../../mk/bsd.prefs.mk"

.if !empty(WXGTK_USE_GTK1:M[Yy][Ee][Ss])
.include "../../x11/gtk/buildlink3.mk"
.else
.include "../../x11/gtk2/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.endif # WXGTK_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
