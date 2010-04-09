# $NetBSD: buildlink3.mk,v 1.7 2010/04/09 08:50:17 tnn Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && !exists(${X11BASE}/lib/pkgconfig/xext.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libXext

.if !defined(LIBXEXT_BUILDLINK3_MK)
LIBXEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXext+=	libXext>=1.1.1
BUILDLINK_PKGSRCDIR.libXext?=	../../x11/libXext

.include "../../x11/libX11/buildlink3.mk"
# XXX don't include xextproto/bl3 here; packages checking for xext.pc must
# include it theirselfes
.endif # LIBXEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXext

.endif
