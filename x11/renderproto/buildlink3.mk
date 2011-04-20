# $NetBSD: buildlink3.mk,v 1.15 2011/04/20 10:00:01 hauke Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	renderproto

.if !defined(RENDERPROTO_BUILDLINK3_MK)
RENDERPROTO_BUILDLINK3_MK:=

.if ${X11_TYPE} == "native"
. include "../../mk/x11.buildlink3.mk"
. if ${BUILTIN_X11_TYPE.native} == "XFree86" || \
     ${BUILTIN_X11_TYPE.native} == "xorg" && \
     empty(BUILTIN_X11_VERSION.xorg)
RENDERPROTO_RENDERPROTO9=1
. endif
.endif

.if defined(RENDERPROTO_RENDERPROTO9)
BUILDLINK_API_DEPENDS.renderproto+=	renderproto>=0.9.3nb1
BUILDLINK_PKGSRCDIR.renderproto?=	../../x11/renderproto9
BUILDLINK_BUILTIN_MK.renderproto=	../../x11/renderproto/builtin.mk
.else
BUILDLINK_API_DEPENDS.renderproto+=	renderproto>=0.9.3nb1
BUILDLINK_PKGSRCDIR.renderproto?=	../../x11/renderproto
.endif

BUILDLINK_DEPMETHOD.renderproto?=	build
.endif # RENDERPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-renderproto
