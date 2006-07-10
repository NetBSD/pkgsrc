# $NetBSD: buildlink3.mk,v 1.11 2006/07/10 21:50:34 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFREE86_LIBS_BUILDLINK3_MK:=	${XFREE86_LIBS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	XFree86-libs
.endif

#
# XFree86-libs must come first so that packages listed later can overwrite
# any symlinks created by buildlinking XFree86-libs.
#
BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXFree86-libs}
BUILDLINK_PACKAGES:=	XFree86-libs ${BUILDLINK_PACKAGES}
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}XFree86-libs

.include "../../mk/bsd.prefs.mk"

.if !empty(XFREE86_LIBS_BUILDLINK3_MK:M+)

BUILDLINK_API_DEPENDS.XFree86-libs+=	XFree86-libs>=4.4.0
BUILDLINK_ABI_DEPENDS.XFree86-libs+=	XFree86-libs>=4.4.0nb7
BUILDLINK_PKGSRCDIR.XFree86-libs?=	../../x11/XFree86-libs
BUILDLINK_LIBDIRS.XFree86-libs?=	${X11ROOT_PREFIX}/lib
BUILDLINK_TRANSFORM.XFree86-libs+=	-e "s|/${X11ROOT_PREFIX}/|/|"

.endif  # XFREE86_LIBS_BUILDLINK3_MK

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
