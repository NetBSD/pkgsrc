# $NetBSD: buildlink3.mk,v 1.19 2015/12/29 04:54:38 dholland Exp $

BUILDLINK_TREE+=	Xaw-Xpm

.if !defined(XAW_XPM_BUILDLINK3_MK)
XAW_XPM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Xaw-Xpm+=	Xaw-Xpm>=1.1
BUILDLINK_ABI_DEPENDS.Xaw-Xpm+=	Xaw-Xpm>=1.1nb2
BUILDLINK_PKGSRCDIR.Xaw-Xpm?=	../../x11/Xaw-Xpm

BUILDLINK_TRANSFORM+=		l:Xaw:Xaw3d

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "modular"
buildlink-Xaw-Xpm-cookie: .PHONY buildlink-Xaw-Xpm-inc-hack

buildlink-Xaw-Xpm-inc-hack: .PHONY buildlink-directories
	[ ! -h ${BUILDLINK_DIR}/include/X11/Xaw ] && \
		${MKDIR} ${BUILDLINK_DIR}/include/X11 && \
		${LN} -s Xaw3d ${BUILDLINK_DIR}/include/X11/Xaw
.endif

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif # XAW_XPM_BUILDLINK3_MK

BUILDLINK_TREE+=	-Xaw-Xpm
