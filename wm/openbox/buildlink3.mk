# $NetBSD: buildlink3.mk,v 1.43 2023/01/29 21:15:02 ryoon Exp $

BUILDLINK_TREE+=	openbox

.if !defined(OPENBOX_BUILDLINK3_MK)
OPENBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openbox+=	openbox>=3.5
BUILDLINK_ABI_DEPENDS.openbox?=	openbox>=3.6.1nb24
BUILDLINK_PKGSRCDIR.openbox?=	../../wm/openbox

pkgbase := openbox
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.openbox:Mimlib2)
.include "../../graphics/imlib2/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.openbox:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # OPENBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-openbox
