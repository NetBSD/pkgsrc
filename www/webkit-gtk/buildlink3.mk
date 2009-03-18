# $NetBSD: buildlink3.mk,v 1.2 2009/03/18 03:13:12 snj Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WEBKIT_GTK_BUILDLINK3_MK:=	${WEBKIT_GTK_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	webkit-gtk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nwebkit-gtk}
BUILDLINK_PACKAGES+=	webkit-gtk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}webkit-gtk

.if ${WEBKIT_GTK_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=1.1.3
BUILDLINK_PKGSRCDIR.webkit-gtk?=	../../www/webkit-gtk
.endif	# WEBKIT_GTK_BUILDLINK3_MK

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
