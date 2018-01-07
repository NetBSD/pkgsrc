# $NetBSD: buildlink3.mk,v 1.6 2018/01/07 13:04:40 rillig Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libxkbfile

.  if !defined(LIBXKBFILE_BUILDLINK3_MK)
LIBXKBFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxkbfile+=	libxkbfile>=0.99.1
BUILDLINK_PKGSRCDIR.libxkbfile?=	../../x11/libxkbfile

.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.  endif # LIBXKBFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxkbfile

.endif
