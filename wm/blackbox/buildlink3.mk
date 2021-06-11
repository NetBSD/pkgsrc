# $NetBSD: buildlink3.mk,v 1.1 2021/06/11 20:17:38 gutteridge Exp $

BUILDLINK_TREE+=	blackbox

.if !defined(BLACKBOX_BUILDLINK3_MK)
BLACKBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blackbox+=	blackbox>=0.70.0
BUILDLINK_ABI_DEPENDS.blackbox+=	blackbox>=0.70.0
BUILDLINK_PKGSRCDIR.blackbox?=		../../wm/blackbox

pkgbase:= blackbox
.include "../../mk/pkg-build-options.mk"

.include "../../x11/libX11/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.blackbox:Mxft2}
.include "../../x11/libXft/buildlink3.mk"
.endif
.endif # BLACKBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-blackbox
