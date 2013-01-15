# $NetBSD: buildlink3.mk,v 1.14 2013/01/15 16:21:35 morr Exp $

BUILDLINK_TREE+=	Xaw3d

.if !defined(XAW3D_BUILDLINK3_MK)
XAW3D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Xaw3d+=	Xaw3d>=1.5
BUILDLINK_ABI_DEPENDS.Xaw3d+=	Xaw3d>=1.5Enb1
BUILDLINK_PKGSRCDIR.Xaw3d?=	../../x11/Xaw3d

BUILDLINK_TRANSFORM+=		l:Xaw:Xaw3d

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "modular"
.PHONY: buildlink-Xaw3d-inc-hack
buildlink-Xaw3d-cookie: buildlink-Xaw3d-inc-hack

buildlink-Xaw3d-inc-hack: buildlink-directories
	[ ! -h ${BUILDLINK_DIR}/include/X11/Xaw ] && \
		${MKDIR} ${BUILDLINK_DIR}/include/X11 && \
		${LN} -s Xaw3d ${BUILDLINK_DIR}/include/X11/Xaw
.endif

.include "../../x11/libXmu/buildlink3.mk"

.endif # XAW3D_BUILDLINK3_MK

BUILDLINK_TREE+=	-Xaw3d
