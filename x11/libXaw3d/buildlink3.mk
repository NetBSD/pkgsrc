# $NetBSD: buildlink3.mk,v 1.2 2016/01/23 03:04:00 markd Exp $

BUILDLINK_TREE+=	libXaw3d

.if !defined(LIBXAW3D_BUILDLINK3_MK)
LIBXAW3D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXaw3d+=	libXaw3d>=1.6.2
BUILDLINK_PKGSRCDIR.libXaw3d?=	../../x11/libXaw3d

BUILDLINK_TRANSFORM+=	l:Xaw:Xaw3d
 
.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "modular"
.PHONY: buildlink-libXaw3d-inc-hack
buildlink-libXaw3d-cookie: buildlink-libXaw3d-inc-hack
 
buildlink-libXaw3d-inc-hack: buildlink-directories
	[ ! -h ${BUILDLINK_DIR}/include/X11/Xaw ] && \
		${MKDIR} ${BUILDLINK_DIR}/include/X11 && \
		${LN} -s Xaw3d ${BUILDLINK_DIR}/include/X11/Xaw
.endif

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# LIBXAW3D_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXaw3d
