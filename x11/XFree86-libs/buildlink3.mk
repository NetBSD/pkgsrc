# $NetBSD: buildlink3.mk,v 1.1 2004/03/28 22:06:15 xtraeme Exp $

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

.if !empty(XFREE86_LIBS_BUILDLINK3_MK:M+)

BUILDLINK_DEPENDS.XFree86-libs+=	XFree86-libs>=4.4.0
BUILDLINK_PKGSRCDIR.XFree86-libs?=	../../XFree86/XFree86-libs
BUILDLINK_TRANSFORM.XFree86-libs+=	-e "s|/X11R6/|/|"

.endif  # XFREE86_LIBS_BUILDLINK3_MK

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
