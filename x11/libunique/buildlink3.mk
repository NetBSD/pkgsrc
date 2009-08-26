# $NetBSD: buildlink3.mk,v 1.3 2009/08/26 19:56:56 sno Exp $

BUILDLINK_TREE+=	libunique

.if !defined(LIBUNIQUE_BUILDLINK3_MK)
LIBUNIQUE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunique+=	libunique>=1.0.4
BUILDLINK_ABI_DEPENDS.libunique?=	libunique>=1.0.8nb1
BUILDLINK_PKGSRCDIR.libunique?=	../../x11/libunique

pkgbase := libunique
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libunique:Mdbus)
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif

.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBUNIQUE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunique
